setx BOOST_MSVC12_INCLUDE   e:\work\code\cpp\include\boost_168
setx BOOST_MSVC12_LIBPATH   e:\work\code\cpp\include\boost_168\libs
setx BOOST_MSVC12_VERSION   168

@rem setx BOOST_PYTHON_STATIC_LIB

setx PYTHON27_INCLUDE c:\prg\Python27\include
setx PYTHON27_LIBPATH c:\prg\Python27\libs
setx PYTHON27_VERSION 27

setx PYTHON27_MSVC12_INCLUDE  c:\prg\Python27\include
setx PYTHON27_MSVC12_LIBPATH  c:\prg\Python27\libs
setx PYTHON27_MSVC12_VERSION  27

setx PYTHON37_INCLUDE c:\prg\Python37\include
setx PYTHON37_LIBPATH c:\prg\Python37\libs
setx PYTHON37_VERSION 37

setx PYTHON37_MSVC12_INCLUDE  c:\prg\Python37\include
setx PYTHON37_MSVC12_LIBPATH  c:\prg\Python37\libs
setx PYTHON37_MSVC12_VERSION  37

setx ICERAY_ROOT %cd%\..

setx PYTHONPATH %PYTHONPATH%;%ICERAY_ROOT%\src;%ICERAY_ROOT%\example
