#include "betterblobdetector.h"

using namespace cv;

BetterBlobDetector::BetterBlobDetector(const SimpleBlobDetector::Params &parameters) : SimpleBlobDetector(parameters)
{

}


void BetterBlobDetector::findBlobs(const cv::Mat &image, const cv::Mat &binaryImage,
                                   vector<Center> &centers, std::vector < std::vector<cv::Point> >&curContours) const
{
	(void)image;
	centers.clear();

	curContours.clear();

	std::vector < std::vector<cv::Point> >contours;
	Mat tmpBinaryImage = binaryImage.clone();
	findContours(tmpBinaryImage, contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);


	for (size_t contourIdx = 0; contourIdx < contours.size(); contourIdx++)
	{
		Center center;
		center.confidence = 1;
		Moments moms = moments(Mat(contours[contourIdx]));
		if (params.filterByArea)
		{
			double area = moms.m00;
			if (area < params.minArea || area >= params.maxArea)
				continue;
		}

		center.location = Point2d(moms.m10 / moms.m00, moms.m01 / moms.m00);

		//compute blob radius
		{
			vector<double> dists;
			for (size_t pointIdx = 0; pointIdx < contours[contourIdx].size(); pointIdx++)
			{
				Point2d pt = contours[contourIdx][pointIdx];
				dists.push_back(norm(center.location - pt));
			}
			std::sort(dists.begin(), dists.end());
			center.radius = (dists[(dists.size() - 1) / 2] + dists[dists.size() / 2]) / 2.;
		}

		centers.push_back(center);
		curContours.push_back(contours[contourIdx]);
	}
}

static std::vector < std::vector<cv::Point> > _contours;

/*const std::vector < std::vector<cv::Point> > BetterBlobDetector::getContours() {
	return _contours;
}*/

void BetterBlobDetector::detectImpl(const cv::Mat& image, std::vector<cv::KeyPoint>& keypoints, std::vector < std::vector<cv::Point> > &contours, const cv::Mat&) const
{
	//TODO: support mask
	contours.clear();

	keypoints.clear();
	Mat grayscaleImage;

	//convert image to grayscale

	if (image.channels() == 3)
		cvtColor(image, grayscaleImage, CV_BGR2GRAY);
	else
		grayscaleImage = image;


	vector < vector<Center> > centers;
	//process image with applying thresholding with several thresholds
	for (double thresh = params.minThreshold; thresh < params.maxThreshold; thresh += params.thresholdStep)
	{
		Mat binarizedImage;
		threshold(grayscaleImage, binarizedImage, thresh, 255, THRESH_BINARY);

		vector < Center > curCenters;
		vector < vector<cv::Point> >curContours, newContours;
		findBlobs(grayscaleImage, binarizedImage, curCenters, curContours);
		vector < vector<Center> > newCenters;
		for (size_t i = 0; i < curCenters.size(); i++)
		{

			bool isNew = true;
			for (size_t j = 0; j < centers.size(); j++)
			{
				double dist = norm(centers[j][ centers[j].size() / 2 ].location - curCenters[i].location);
				isNew = dist >= params.minDistBetweenBlobs && dist >= centers[j][ centers[j].size() / 2 ].radius && dist >= curCenters[i].radius;
				if (!isNew)
				{
					centers[j].push_back(curCenters[i]);

					size_t k = centers[j].size() - 1;
					while ( k > 0 && centers[j][k].radius < centers[j][k - 1].radius )
					{
						centers[j][k] = centers[j][k - 1];
						k--;
					}
					centers[j][k] = curCenters[i];

					break;
				}
			}
			if (isNew)
			{
				newCenters.push_back(vector<Center> (1, curCenters[i]));
				newContours.push_back(curContours[i]);
				//centers.push_back(vector<Center> (1, curCenters[i]));
			}
		}
		std::copy(newCenters.begin(), newCenters.end(), std::back_inserter(centers));
		std::copy(newContours.begin(), newContours.end(), std::back_inserter(contours));
	}

	for (size_t i = 0; i < centers.size(); i++)
	{
		if (centers[i].size() < params.minRepeatability)
			continue;
		Point2d sumPoint(0, 0);
		double normalizer = 0;
		for (size_t j = 0; j < centers[i].size(); j++)
		{
			sumPoint += centers[i][j].confidence * centers[i][j].location;
			normalizer += centers[i][j].confidence;
		}
		sumPoint *= (1. / normalizer);
		KeyPoint kpt(sumPoint, (float)(centers[i][centers[i].size() / 2].radius));
		keypoints.push_back(kpt);
		contours.push_back(contours[i]);
	}
}
