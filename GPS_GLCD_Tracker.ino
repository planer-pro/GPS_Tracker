#include <glcd.h>

#define GPS_POINTS_COUNT 6 //колличество точек в массиве данных с gps
#define LCD_WIDTH 128 //ширина используемого дисплея
#define LCD_HEIGHT 64 //высота используемого дисплея
float gps_data_XY[GPS_POINTS_COUNT][2]; //создаем двухмерный массив величиной GPS_POINTS_COUNT


void setup()
{
	GLCD.Init();

	FillArray();
	GpsToGlcd(gps_data_XY, 800);


}

void loop()
{

}

void FillArray()
{
	gps_data_XY[0][0] = 53.9084483;
	gps_data_XY[1][0] = 53.8914527;
	gps_data_XY[2][0] = 53.8910065;
	gps_data_XY[3][0] = 53.9090750;
	gps_data_XY[4][0] = 53.9161915;
	gps_data_XY[5][0] = 53.9284483;
	gps_data_XY[0][1] = 27.5749698;
	gps_data_XY[1][1] = 27.5748437;
	gps_data_XY[2][1] = 27.6005312;
	gps_data_XY[3][1] = 27.6054490;
	gps_data_XY[4][1] = 27.5926308;
	gps_data_XY[5][1] = 27.5826308;
}


void GpsToGlcd(float points [GPS_POINTS_COUNT][2], float zoom)
{

	float start_x = points[0][0];
	float start_y = points[0][1];


	for (int i = 0; i < GPS_POINTS_COUNT; i++)
	{
		points[i][0] -= start_x;
		points[i][1] -= start_y;
		points[i][0] *= zoom;
		points[i][1] *= zoom;
	}

	DrawPoints(points);
}

void DrawPoints(float points[GPS_POINTS_COUNT][2])
{
	for (int i = 0; i < GPS_POINTS_COUNT-1; i++)
	{
		int x1 = points[i][0] + LCD_WIDTH / 2;
		int x2 = points[i + 1][0] + LCD_WIDTH / 2;
		int y1 = points[i][1] + LCD_HEIGHT / 2;
		int y2 = points[i + 1][1] + LCD_HEIGHT / 2;

		GLCD.DrawLine(x1, y1, x2, y2);
	}
}