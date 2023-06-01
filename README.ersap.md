## Getting, Building, and Installing the C++ Disruptor

- clone the distribution of Disruptor-cpp from the Jefferson clone of it (since some jlab specific changes were made)


    https://github.com/JeffersonLab/Disruptor-cpp.git
    
        or
        
    gh repo clone JeffersonLab/Disruptor-cpp


- build & install it into a specified dir (includes go into $INSTALL_DIR/include)


    cd Disruptor-cpp
    mkdir build
    cd build
    cmake -DINSTALL_DIR=/daqfs/ersap/installation ..
    make install

- build & install it as part of CODA (includes go into $CODA_INSTALL/common/include)


    cd Disruptor-cpp
    mkdir build
    cd build
    cmake -DCODA_INSTALL=/daqfs/ersap/installation ..
    make install


or simply define the CODA environmental variable (includes go into $CODA/common/include)


    cd Disruptor-cpp
    mkdir build
    cd build
    cmake  ..
    make install

