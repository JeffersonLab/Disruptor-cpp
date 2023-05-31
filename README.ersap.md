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

