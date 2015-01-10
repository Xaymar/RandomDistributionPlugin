RandomDistribution (Unreal Engine 4 Plugin)
=======================

RandomDistribution allows you to quickly create randomly distributed points in 2D or 3D space. Contains classes and blueprint nodes to use.

Distributors (random generators)
----------

* C++11 [uniform_real_distribution](http://www.cplusplus.com/reference/random/uniform_real_distribution/)
* Unreal Engine 4 [FRandomStream](https://docs.unrealengine.com/latest/INT/API/Runtime/Core/Math/FRandomStream/index.html)
* [Poisson-Disc Sampling](http://www.jasondavies.com/poisson-disc/) (Implemented using [this paper](http://www.cs.ubc.ca/~rbridson/docs/bridson-siggraph07-poissondisk.pdf))

Prerequisites
-------------
You will need the source of Unreal Engine 4 (any version above 4.2 will work) to be available for building and a compiler supporting C++11. That's pretty much it.

Installation
------------
1. Download and extract source code into a subfolder called _RandomDistribution_ in your projects _Plugins_ folder.
2. Rebuild your projects Visual Studio project files.
3. Rebuild your project from Visual Studio while the editor is closed.
4. Enable the plugin if it hasn't already enabled itself.

*Alternative:* You can use LazyInstall.bat on Windows, just drag & drop your project folder onto it. Be sure to have a backup in case it fucks up though, no guarantees.