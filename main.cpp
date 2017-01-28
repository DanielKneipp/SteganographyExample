#include <iostream>
#include <string>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

void steg( cv::Mat img, std::string msg )
{
    int imageSize = img.cols * img.rows * img.channels();
    int step = imageSize / msg.size();
    for( int i = 0; i < (step * msg.size()); i = i + step )
    {
        img.data[ i ] = static_cast< uchar >( msg[ ( i/step ) ] );
    }
    cv::imwrite( "stegaedImg.png", img );
    std::cout << "\n S: " << step << "\n T: " << msg.size() << "\n\n";
}

void dteg( cv::Mat img, int step, int size )
{
    std::string msg;
    for( int i = 0; i < (step * size); i = i + step )
    {
        msg += static_cast< char >( img.data[ i ] ) ;
    }
    std::cout << "\n Message: " << msg << "\n\n";
}


int main( int argn, char** argv )
{
    if( argn < 3 )
    {
        std::cout << "Usage: steg c|d <imgIn.png>\n";
        return 1;
    }

    cv::Mat img = cv::imread( argv[ 2 ] );

    if( !img.data )
    {
        std::cout << "Error: Could not open or find the image on " << argv[1] << std::endl;
        return 2;
    }

    switch ( argv[ 1 ][ 0 ] )
    {
        case 'c':
        {
            std::string message;
            std::cout << "\n Message: ";
            std::getline( std::cin, message );
            steg( img, message );
        } break;
        case 'd':
        {
            int step = 0;
            int size = 0;
            std::cout << "\n S: ";
            std::cin >> step;
            std::cout << " T: ";
            std::cin >> size;
            dteg( img, step, size );
        } break;
        default:
        {
            std::cout << "Usage: steg c|d <imgIn.png>\n";
            return 1;
        }
    }

    return 0;
}

