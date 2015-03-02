Random Distribution Plugin (Unreal Engine 4)
=======================

Random Distribution adds classes and Blueprint nodes to quickly generate points in 1D, 2D or 3D space.

Generators
----------

* C++11 [uniform_real_distribution](http://www.cplusplus.com/reference/random/uniform_real_distribution/)
* Unreal Engine 4 [FRandomStream](https://docs.unrealengine.com/latest/INT/API/Runtime/Core/Math/FRandomStream/index.html)
* [Poisson-Disc Sampling](http://www.jasondavies.com/poisson-disc/) (Implemented using [this paper](http://www.cs.ubc.ca/~rbridson/docs/bridson-siggraph07-poissondisk.pdf))

Installation (Binary)
---------------------

1. Have a binary version of the engine installed or compiled.
2. Drop the plugin into either <UE4Source>\Engine\Plugins or <Project>\Plugins.
3. Restart the Editor.

**Windows Only:** LazyInstall.bat allows you to make a directory junction to the plugin by just dragging your <UE4Source>\Engine or <Project> folder onto it, making it easy to maintain multiple projects using this plugin. 

Installation (Source)
---------------------

1. Have a source version of engine downloaded and compiled.
2. Drop the plugin into either <UE4Source>\Engine\Plugins or <Project>\Plugins.
3. Recompile the engine or the project to create binary files.
4. (Optional) Restart the Editor.