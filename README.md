Pixelorama pxo files thumbnail generator for KDE's Dolphin. Works for KDE Plasma 6.

## How to install
cmake -DCMAKE_PREFIX_PATH=/usr/lib64/cmake/Qt6 -DQT_MAJOR_VERSION=6 ..
make
sudo make install

Then go to Configure Dolphin and enable "Pixelorama File Thumbnailer".
