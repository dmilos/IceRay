# IceRay Ray tracer

 - Description \
    An ancient ray tracer that I finally put in public.

 - Status: \
    Still in development, near beta status.

## Key features:
 - Like any ancient ray tracers posses.

## Examples

### Camera
![cylinder-horizontal](data/sample/camera/cylinder-horizontal.png)
![cylinder-vertical](data/sample/camera/cylinder-vertical.png)
![dof-cone](data/sample/camera/dof-cone.png)
![dof-focus](data/sample/camera/dof-focus.png)
![flat-orthogonal](data/sample/camera/flat-orthogonal.png)
![flat-perspective](data/sample/camera/flat-perspective.png)
![flat-super-X](data/sample/camera/flat-super-X.png)
![flat-super-Y](data/sample/camera/flat-super-Y.png)
![sphere-fisheye](data/sample/camera/sphere-fisheye.png)
![sphere-horizontal](data/sample/camera/sphere-horizontal.png)
![sphere-vertical](data/sample/camera/sphere-vertical.png)

### Geometry

#### Flat
![box](data/sample/geometry/flat/box.png)
![disc](data/sample/geometry/flat/disc.png)
![plane](data/sample/geometry/flat/plane.png)
![triangle](data/sample/geometry/flat/triangle.png)

#### Quadric
![cone](data/sample/geometry/quadric/cone.png)
![cylinder](data/sample/geometry/quadric/cylinder.png)
![img](data/sample/geometry/quadric/hyper-cone.png)
![img](data/sample/geometry/quadric/hyper-cylinder.png)
![img](data/sample/geometry/quadric/hyper-negative.png)
![img](data/sample/geometry/quadric/hyper-nuke.png)
![img](data/sample/geometry/quadric/hyper-sphere.png)
![paraboloid](data/sample/geometry/quadric/paraboloid.png)
![img](data/sample/geometry/quadric/quadric-cone.png)
![img](data/sample/geometry/quadric/quadric-cylinder.png)
![img](data/sample/geometry/quadric/quadric-hyperboloid.png)
![img](data/sample/geometry/quadric/quadric-paraboloid.png)
![img](data/sample/geometry/quadric/quadric-sphere.png)
![saddle](data/sample/geometry/quadric/saddle.png)
![Unit Sphere](data/sample/geometry/quadric/usphere.png)

#### Transformation
![translate](data/sample/geometry/transform/translate.png)
![affine](data/sample/geometry/transform/affine.png)
![mblur](data/sample/geometry/transform/mblur.png)

#### Misc
![img](data/sample/geometry/blobby.png)
![img](data/sample/geometry/intersect.png)
![img](data/sample/geometry/torus.png)
![img](data/sample/geometry/vacuum.png)

### Light
![area](data/sample/light/area.png)
![circle](data/sample/light/circle.png)
![disc](data/sample/light/disc.png)
![line](data/sample/light/line.png)
![point](data/sample/light/point.png)
![reflector](data/sample/light/reflector.png)
![spline](data/sample/light/spline.png)
![sunPoint](data/sample/light/sunPoint.png)

### Material

#### Illumination
![AshShiCmpl](data/sample/material/illumination/AshShiCmpl.png)
![AshShiDif](data/sample/material/illumination/AshShiDif.png)
![AshShiSpec](data/sample/material/illumination/AshShiSpec.png)
![ONf29](data/sample/material/illumination/ONf29.png)
![ONp44](data/sample/material/illumination/ONp44.png)
![ambient](data/sample/material/illumination/ambient.png)
![Beckmann](data/sample/material/illumination/beckmann.png)
![Blinn](data/sample/material/illumination/blinn.png)
![Gaussian](data/sample/material/illumination/gaussian.png)
![img](data/sample/material/illumination/hs-lambert.png)
![img](data/sample/material/illumination/hs-phong.png)
![Lambert](data/sample/material/illumination/lambert.png)
![Phong](data/sample/material/illumination/phong.png)
![img](data/sample/material/illumination/ward-aprox.png)
![img](data/sample/material/illumination/ward-iso.png)
![img](data/sample/material/illumination/ward-real.png)

#### Pattern
![checker](data/sample/material/pattern/function/checker.png)
![hexagon](data/sample/material/pattern/function/hexagon.png)
![normal2ambient](data/sample/material/pattern/function/normal2ambient.png)
![waveSaw](data/sample/material/pattern/function/waveSaw.png)
![waveSin](data/sample/material/pattern/function/waveSin.png)
![Crackle](data/sample/material/pattern/noise/Crackle.png)
![Perlin](data/sample/material/pattern/noise/Perlin.png)
![Value](data/sample/material/pattern/noise/Value.png)
![img](data/sample/material/pattern/noise/noiseCells.png)
![cartesian2cylindric](data/sample/material/pattern/transform/cartesian2cylindric.png)
![cartesian2spherical](data/sample/material/pattern/transform/cartesian2spherical.png)
![img](data/sample/material/pattern/transform/cartesian2tablecloth.png)
![cylindric2cartesian](data/sample/material/pattern/transform/cylindric2cartesian.png)
![cylindric2spherical](data/sample/material/pattern/transform/cylindric2spherical.png)

#### Transmission
![img](data/sample/material/transmission/mirrorP.png)
![img](data/sample/material/transmission/mirrorS.png)
![img](data/sample/material/transmission/reflect-plane-One.png)
![img](data/sample/material/transmission/reflect-sphere-One.png)
![img](data/sample/material/transmission/reflectB-plane-Grid-plane.png)
![img](data/sample/material/transmission/reflectB-plane-Hex-plane.png)
![img](data/sample/material/transmission/reflectB-plane-Rand-plane.png)
![img](data/sample/material/transmission/reflectB-plane-VDC-plane.png)
![img](data/sample/material/transmission/reflectB-sphere-Grid.png)
![img](data/sample/material/transmission/reflectB-sphere-Hex.png)
![img](data/sample/material/transmission/reflectB-sphere-Rand.png)
![img](data/sample/material/transmission/reflectB-sphere-VDC.png)
![img](data/sample/material/transmission/refractArbitrary.png)
![img](data/sample/material/transmission/refractFresnel.png)
![img](data/sample/material/transmission/refractOne.png)
![img](data/sample/material/transmission/refractSchlick.png)


# Install
  - install git
  - install cmake
  - install python
    - pip install scons
    - pip install nucleotide
  - git clone http://github.com/dmilos/IceRay.git
  - git submodule init
  - git submodule update
  - Build using SCons
    - cd ./IceRay/work/build/scons/cdll
    - scons
  - Build using CMake 
    - cd ./IceRay/work/build/cmake
    - run make.bat on Windows or make.sh on Unix
  - put $\src and $\example in to PYTHONPATH path
  - run some examples in $\example\test2
