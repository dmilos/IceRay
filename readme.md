# IceRay Ray tracer

 - Description \
    An ancient ray tracer that I finally put in public.

 - Status: \
    Still in development.

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
![sphere-vertica](data/sample/camera/sphere-vertical.png)


### Geometry

#### Flat

![img](data/sample/geometry/flat/box.png)
![img](data/sample/geometry/flat/disc.png)
![img](data/sample/geometry/flat/plane.png)
![img](data/sample/geometry/flat/triangle.png)

#### Quadric
![img](data/sample/geometry/quadric/cone.png)
![img](data/sample/geometry/quadric/cylinder.png)
![img](data/sample/geometry/quadric/hyper-cone.png)
![img](data/sample/geometry/quadric/hyper-cylinder.png)
![img](data/sample/geometry/quadric/hyper-negative.png)
![img](data/sample/geometry/quadric/hyper-nuke.png)
![img](data/sample/geometry/quadric/hyper-sphere.png)
![img](data/sample/geometry/quadric/paraboloid.png)
![img](data/sample/geometry/quadric/quadric-cone.png)
![img](data/sample/geometry/quadric/quadric-cylinder.png)
![img](data/sample/geometry/quadric/quadric-hyperboloid.png)
![img](data/sample/geometry/quadric/quadric-paraboloid.png)
![img](data/sample/geometry/quadric/quadric-sphere.png)
![img](data/sample/geometry/quadric/saddle.png)
![img](data/sample/geometry/quadric/usphere.png)

#### Transformation
![img](sample\geometry\transform\affine.png)
![img](sample\geometry\transform\translate.png)

#### Misc
![img](data\sample\geometry\blobby.png)
![img](data\sample\geometry\intersect.png)
![img](data\sample\geometry\mblur.png)
![img](data\sample\geometry\torus.png)
![img](data\sample\geometry\vacuum.png)

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
![img](data/sample/material/illumination/AshShiCmpl.png)
![img](data/sample/material/illumination/AshShiDif.png)
![img](data/sample/material/illumination/AshShiSpec.png)
![img](data/sample/material/illumination/ONf29.png)
![img](data/sample/material/illumination/ONp44.png)
![img](data/sample/material/illumination/ambient.png)
![img](data/sample/material/illumination/beckmann.png)
![img](data/sample/material/illumination/blinn.png)
![img](data/sample/material/illumination/gaussian.png)
![img](data/sample/material/illumination/hs-lambert.png)
![img](data/sample/material/illumination/hs-phong.png)
![img](data/sample/material/illumination/lambert.png)
![img](data/sample/material/illumination/phong.png)
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
![img](data/sample/material/pattern/transform/cartesian2cylindric.png)
![img](data/sample/material/pattern/transform/cartesian2spherical.png)
![img](data/sample/material/pattern/transform/cartesian2tablecloth.png)
![img](data/sample/material/pattern/transform/cylindric2cartesian.png)
![img](data/sample/material/pattern/transform/cylindric2spherical.png)

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


```python
TODO
```

# Install
  - install git
  - install python
    - install python with dev options
    - pip install scons
    - pip install nucleotide
  - install boost
  - git clone http://github.com/dmilos/IceRay.git
  - git submodule init
  - git submodule update
  - modify ```build/set-env.bat``` according to your configuration
  - run ```build/set-env.bat```
  - cd ./IceRay/work/build/scons/python
  - scons
  - rename *dll/*so from temp/IceRayLib-.../dll to IceRayCpp.pyd and copy in to your PYTHONPATH folder
  - run some examples.


# Boost vs python pre-built binaries
   Boost  | MSVC/Python | MSVC/Python
  ------- |-------------|--------
   1.68   | 120/27      | 140/37
   1.70   | 120/27      | 140/37
  -----------------------------

