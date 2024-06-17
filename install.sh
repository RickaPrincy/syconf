#! /bin/bash
git clone https://github.com/RickaPrincy/syconf
cd syconf 
mkdir build
cd build
cmake -S .. -B .
sudo make install
cd ../..
rm -rf Templi
