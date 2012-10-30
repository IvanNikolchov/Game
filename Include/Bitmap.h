#ifndef BITMAP_DEFINED
#define BITMAP_DEFINED

// Bitmap header definitions
#pragma pack(push,2) // Disable automatic alignment of structure fields

typedef struct BITMAP_INFO
{
  unsigned long size;
  long width;
  long height;
  unsigned short planes;
  unsigned short bitCount;
  unsigned long compression;
  unsigned long sizeImage;
  long XPelsPerMeter;
  long YPelsPerMeter;
  unsigned long clrUsed;
  unsigned long clrImportant;
  unsigned char rgbBlue;
  unsigned char rgbGreen;
  unsigned char rgbRed;
  unsigned char rgbReserved;
} BMPINFO;

typedef struct BITMAP_FILE_HEADER
{
  unsigned short type;
  unsigned long size;
  unsigned short reserved1;
  unsigned short reserved2;
  unsigned long offBits;
} BMPFILEHEADER;
#pragma pack(pop)

class Bitmap
{
public:
  Bitmap(char* filename);
  virtual ~Bitmap();
  int getWidth() { return width; }
  int getHeight() { return height; }
  unsigned char* getData() { return data; }
  
private:
  unsigned char* data;
  int width;
  int height;
  int dataSize;
  bool loadBitmap(char* filename);
};

#endif