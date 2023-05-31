## Getting, Building, and Installing the C++ Disruptor

- clone the distribution of Disruptor-cpp from the Jefferson clone of it (since some jlab specific changes were made)


    https://github.com/JeffersonLab/Disruptor-cpp.git
    
        or
        
    gh repo clone JeffersonLab/Disruptor-cpp


- build & install it into a specified dir


    cd Disruptor-cpp
    mkdir build
    cd build
    cmake -DDIS_INSTALL=/daqfs/ersap/installation ..
    make install

- build & install it as part of CODA (slightly different include dir)


    cd Disruptor-cpp
    mkdir build
    cd build
    cmake -DCODA_INSTALL=/daqfs/ersap/installation ..
    make install


or simply define the CODA environmental variable and do


    cd Disruptor-cpp
    mkdir build
    cd build
    cmake  ..
    make install

