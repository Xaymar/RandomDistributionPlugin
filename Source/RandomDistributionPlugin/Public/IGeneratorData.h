#include "RandomDistributionPluginPrivatePCH.h"
#include "IGenerator.h"

namespace RandomDistributionPlugin {
	class IGeneratorData {
	public:
		virtual ~IGeneratorData() {};

	private:
		IGenerator* Parent = NULL;
		double Width, Height, Depth = 0;
	};
};