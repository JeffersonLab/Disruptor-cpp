## Disruptor Overview
This fantastic, award-winning software package was originally written in Java
for stock trading and then ported to C++ due its popularity. It implements
blazingly fast ring buffers and it's lock free for single producer rings.
It's also thread-safe, eliminates cache-unfriendly false-sharing,
uses opportunistic batching, and uses pre-allocated arrays and so supports
cache-striding. It fills an empty spot in the C++ ecosystem which is mysteriously
short on blocking queues. This particular repo is a fork of the original on which
a few small changes have been made.


Important disruptor-related links:

- [Java Disruptor](https://github.com/LMAX-Exchange/disruptor)
- [Parent C++ Disruptor](https://github.com/Abc-Arbitrage/Disruptor-cpp)
- [Disruptor papers](https://lmax-exchange.github.io/disruptor/)
- [Trish Gee's Disruptor Blogs](https://trishagee.com/?s=disruptor)
- [Java Magazine Article](https://archive.org/details/JavaMagazine2012.0304/page/n55/mode/2up)
- [Original README File](https://github.com/JeffersonLab/Disruptor-cpp/blob/master/README.md).


## Getting, Building, and Installing the C++ Disruptor

Clone the distribution of Disruptor-cpp from the Jefferson fork of it since some jlab specific changes were made


    https://github.com/JeffersonLab/Disruptor-cpp.git
    
        or
        
    gh repo clone JeffersonLab/Disruptor-cpp


Build & install it into $INSTALL_DIR/include, $INSTALL_DIR/lib, and $INSTALL_DIR/bin


    cd Disruptor-cpp
    mkdir build
    cd build
    cmake -DINSTALL_DIR=/daqfs/ersap/installation ..
    make install

Build & install it as part of CODA into $CODA_INSTALL/common/include, $CODA_INSTALL/&lt;arch&gt;/lib, and  $CODA_INSTALL/&lt;arch&gt;/bin


    cd Disruptor-cpp
    mkdir build
    cd build
    cmake -DCODA_INSTALL=/daqfs/ersap/installation ..
    make install


Or simply define the CODA environmental variable and install into $CODA/common/include, $CODA/&lt;arch&gt;/lib, and  $CODA/&lt;arch&gt;/bin


    setenv CODA /blah/blah
    cd Disruptor-cpp
    mkdir build
    cd build
    cmake  ..
    make install
