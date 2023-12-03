#include <iostream>
#include <iostream>
#include <unordered_map>

class ImageDownloader {
public:
    virtual void downloadImage(const std::string& url) = 0;
};

class RealImageDownloader : public ImageDownloader {
public:
    void downloadImage(const std::string& url) override {
        std::cout << "Загрузка изображения с " << url << std::endl;
    }
};

class ImageProxy : public ImageDownloader {
private:
    RealImageDownloader realDownloader;
    std::unordered_map<std::string, bool> imageCache;

public:
    void downloadImage(const std::string& url) override {
        if (imageCache.find(url) != imageCache.end()) {
            std::cout << "Изображение уже находится в кэше." << std::endl;
        }
        else {
            std::cout << "Изображения нет в кэше. Загрузка." << std::endl;
            realDownloader.downloadImage(url);
            imageCache[url] = true;
        }
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    ImageProxy imageProxy;
    imageProxy.downloadImage("/image1.jpg");
    imageProxy.downloadImage("/image2.jpg");
    imageProxy.downloadImage("/image1.jpg");  

    return 0;
}

