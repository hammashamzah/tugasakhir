/* Header ini digunakan sebagai jembatan penghubung variabel ataupun objek global yang akan digunakan pada
 * berbagai class dari beberapa file. header yang di-include hanya boleh header yang digunakan untuk variabel global
 */

#ifndef OBJECTVARIABLE
#define OBJECTVARIABLE
#define JUMLAH_PLAYER_TEAM_A 11
#define JUMLAH_PLAYER_TEAM_B 11
#define JUMLAH_PLAYER 22
#define rect_player_size 10
#define marginKiriField 12
#define marginAtasField 20


#include <QPoint>
#include "playervisual.h"
#include "coordinateconverter.h"

extern int playerIdSelected;
extern QPoint playerFormation[JUMLAH_PLAYER];
extern playerVisual player_visual[JUMLAH_PLAYER];
extern CoordinateConverter konversi;

#endif // OBJECTVARIABLE
