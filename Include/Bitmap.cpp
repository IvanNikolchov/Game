#include "Bitmap.h"
#include <iostream>
#include <stdio.h>
using namespace std;

Bitmap::Bitmap(char* filename)
{
  if(!loadBitmap(filename))
  {
    cout << "Unable to load " << filename << " !" << endl;
    cout << "The file is missing, damaged or not a valid bitmap file!" << endl;
  }
}

Bitmap::~Bitmap()
{
  if(data != NULL)
    delete data;
}

/** Reads bitmap image in memory. */
bool Bitmap::loadBitmap(char* filename)
{
  FILE* file;
  BMPFILEHEADER header;
  BMPINFO info;
  int infoSize;

  if ((file = fopen(filename, "rb")) == NULL)
    return false;

  fread(&header, sizeof (BMPFILEHEADER), 1, file);

  if (header.type != 'MB') /* Check for BM reversed */
  {
    fclose(file);
    return false;
  };

  infoSize = header.offBits - sizeof (BMPFILEHEADER);
  fread(&info, infoSize, 1, file);

  dataSize = info.sizeImage;
  if(dataSize == 0)
    dataSize = (info.width * info.bitCount + 7) / 8 * (info.height > 0 ? info.height : -info.height);

  data = new unsigned char[dataSize];
  width = info.width;
  height = info.height;
  fread(data, sizeof (unsigned char), dataSize, file);
  fclose(file);
  return true;
}