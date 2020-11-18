#include <assert.h>
#include "bitmap.h"

using namespace std;

PixelMatrix rgb2gray(PixelMatrix& bmp);
PixelMatrix blur_img(PixelMatrix& bmp, int size);
PixelMatrix remove_color(PixelMatrix& bmp, int color);
PixelMatrix mask_img(PixelMatrix& bmp, string mask_path);
int validate(const PixelMatrix& bmp);

int main()
{
    char op;
    int tmp;
    string path;

    Bitmap image;
    PixelMatrix bmp;
    PixelMatrix modified_bmp;
    Pixel rgb;
  
    cin >> path;
    image.open(path);
    bool validBmp = image.isImage();
    assert(validBmp);

    bmp = image.toPixelMatrix();

    // bmp is vector with size = Height * Width * 3 (RGB)
    // For example to access pixel's red value at (0,0) 
    // int red_value = bmp[0][0][0];

    cin >> op;
    switch(op) {
        case 'g' :
            modified_bmp = rgb2gray(bmp);
            break;

        case 'b' :
            cin >> tmp; 
            modified_bmp = blur_img(bmp, tmp);
            break;

        case 'r' : 
            cin >> tmp; 
            modified_bmp = remove_color(bmp, tmp);
            break;
        
        case 'm' :
            cin >> path;
            modified_bmp = mask_img(bmp, path);
            break;
    }
    cout << validate(modified_bmp) << endl;

    // Uncomment following two line to show result image;
    image.fromPixelMatrix(modified_bmp);
    image.save("modified.bmp");
    return 0;
}

PixelMatrix rgb2gray(PixelMatrix& bmp)
{
    PixelMatrix gray = bmp;
    for (int i = 0; i < gray.size(); ++i) {
        for (int j = 0; j < gray[i].size(); ++j) {
                gray[i][j][0]=(bmp[i][j][0]+bmp[i][j][1]+bmp[i][j][2])/3;
                gray[i][j][1]=(bmp[i][j][0]+bmp[i][j][1]+bmp[i][j][2])/3;
                gray[i][j][2]=(bmp[i][j][0]+bmp[i][j][1]+bmp[i][j][2])/3;
        }
    }
    return gray;
}

PixelMatrix remove_color(PixelMatrix& bmp, int color)
{
    assert(color >= 0 && color <3);
    PixelMatrix bmp_remove_color = bmp;
    for (int i = 0; i < bmp_remove_color.size(); ++i) {
        for (int j = 0; j < bmp_remove_color[i].size(); ++j) {
                bmp_remove_color[i][j][color]=0;
        }
    }
    return bmp_remove_color;
}

PixelMatrix mask_img(PixelMatrix& bmp, string mask_path)
{
    Bitmap image;
    PixelMatrix mask;
    PixelMatrix masked_img = bmp;

    image.open(mask_path);
    bool validBmp = image.isImage();
    assert(validBmp);
    
    mask = image.toPixelMatrix();
    for (int i = 0; i < mask.size(); ++i) {
        for (int j = 0; j < mask[i].size(); ++j) {
            for (int k = 0; k < 3; ++k) {
                masked_img[i][j][k]=bmp[i][j][k]*mask[i][j][k]/255;
            }
        }
    }
    return masked_img;
}

/**
 *  This function is for blur, you don't have to implement, 
 *  I have implement for you :)
 *  You can take it as reference.
**/
PixelMatrix blur_img(PixelMatrix& bmp, int size)
{
    PixelMatrix blur = bmp;
    for (int i = 0; i < blur.size()-size; ++i) {
        for (int j = 0; j < blur[i].size()-size; ++j) {
            for (int k = 0; k < 3; ++k) {
                for (int l =1; l < size*size; ++l) {
                    blur[i][j][k] += blur[i+(l/size)][j+(l % size)][k];
                }
                blur[i][j][k] /= (size * size);
            }
        }
    }
    return blur;
}

int validate(const PixelMatrix& bmp)
{
    int ret = 0;
    for (int i = 0; i < bmp.size(); ++i) {
        for (int j = 0; j < bmp[i].size(); ++j) {
            for (int k = 0; k < 3; ++k) {
                ret += bmp[i][j][k];
            }
        }
    }
    return ret;
}
