## Getting, Building, and Installing the C++ Disruptor

- clone the distribution of Disruptor-cpp from the Jefferson clone of it (since some jlab specific changes were made)


    https://github.com/JeffersonLab/Disruptor-cpp.git
    
        or
        
    gh repo clone JeffersonLab/Disruptor-cpp


- build & install it into $INSTALL_DIR/include, $INSTALL_DIR/lib, and $INSTALL_DIR/bin


    cd Disruptor-cpp
    mkdir build
    cd build
    cmake -DINSTALL_DIR=/daqfs/ersap/installation ..
    make install

- build & install it as part of CODA into $CODA_INSTALL/common/include, $CODA_INSTALL/&lt;arch&gt;/lib, and  $CODA_INSTALL/&lt;arch&gt;/bin


    cd Disruptor-cpp
    mkdir build
    cd build
    cmake -DCODA_INSTALL=/daqfs/ersap/installation ..
    make install


or simply define the CODA environmental variable and install into $CODA/common/include, $CODA/&lt;arch&gt;/lib, and  $CODA/&lt;arch&gt;/bin


    setenv CODA /blah/blah
    cd Disruptor-cpp
    mkdir build
    cd build
    cmake  ..
    make install

##### Add some text