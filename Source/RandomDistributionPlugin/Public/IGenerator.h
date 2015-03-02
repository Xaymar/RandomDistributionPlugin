#include "RandomDistributionPluginPrivatePCH.h"
#include <memory>

namespace RandomDistributionPlugin {

	class IGenerator {
	public:
		virtual ~IGenerator() {}

		/**
		 * Returns a shared copy of the Size array.
		 *
		 * @return std::shared_ptr<double*>
		 */virtual TSharedPtr<double*> GetSize() { return MakeShareable<double*>(new double[3]{ m_Size[0], m_Size[1], m_Size[2] }); }

		/**
		 * Changes the Size of the generated area.
		 *
		 * @param  pWidth Width of the generated area.
		 * @param  pHeight Height of the generated area.
		 * @param  pDepth Depth of the generated area.
		 * @return void
		 */virtual void SetSize(double pWidth, double pHeight, double pDepth) { this->m_Size[0] = pWidth; this->m_Size[1] = pHeight; this->m_Size[2] = pDepth; }

		/**
		 * Retrieves the Width of the generated area.
		 *
		 * @return double
		 */virtual double GetWidth() { return m_Size[0]; }

		/**
		 * Helper method to quickly change the Width of the generated area.
		 *
		 * @param  pWidth Width of the generated area.
		 * @return void
		 */virtual void SetWidth(double pWidth) { m_Size[0] = pWidth; }

		/**
		* Retrieves the Height of the generated area.
		*
		* @return double
		*/virtual double GetHeight() { return m_Size[1]; }

		/**
		* Helper method to quickly change the Height of the generated area.
		*
		* @param  pHeight Height of the generated area.
		* @return void
		*/virtual void SetHeight(double pHeight) { m_Size[1] = pHeight; }

		/**
		* Retrieves the Depth of the generated area.
		*
		* @return double
		*/virtual double GetDepth() { return m_Size[2]; }

		/**
		* Helper method to quickly change the Depth of the generated area.
		*
		* @param  pDepth Depth of the generated area.
		* @return void
		*/virtual void SetDepth(double pDepth) { m_Size[2] = pDepth; }

		/** 
		 * Returns a shared copy of the Wrap array.
		 *
		 * @return std::shared_ptr<bool*>
		 */virtual TSharedPtr<bool*> GetWrap() { return MakeShareable<bool*>(new bool[3]{m_Wrap[0], m_Wrap[1], m_Wrap[2]}); }

		/** 
		 * Changes how the generated area repeats.
		 *
		 * @param  pWrapX Repeat the area on the X axis.
		 * @param  pWrapY Repeat the area on the Y axis.
		 * @param  pWrapZ Repeat the area on the Z axis.
		 * @return void
		 */virtual void SetWrap(bool pWrapX, bool pWrapY, bool pWrapZ) { this->m_Wrap[0] = pWrapX; this->m_Wrap[1] = pWrapY; this->m_Wrap[2] = pWrapZ; }

		virtual int GetSeed() { return m_Seed; }

		virtual void SetSeed(int pSeed) { m_Seed = pSeed; }

		/** 
		 * Reserves any memory that is required to generate and store the created FVectors.
		 *
		 * @return void
		 */virtual void Initialize() = 0;

		/** 
		 * Releases any reserved memory from the generator.
		 *
		 * @return void
		 */virtual void Deinitialize() = 0;

		/** 
		 * Generates a new set of FVectors and returns them.
		 *
		 * @param  pIterations How many Iterations should be gone through.
		 * @return FVector*
		 */virtual FVector* Generate(UINT64 pIterations) = 0;

		/** 
		 * Retrieves all currently generated points
		 *
		 * Long Description Here,
		 * May Be Multiple Lines Long.
		 *
		 * @return FVector*
		 */virtual FVector* Retrieve() = 0;

	protected:
		// Size of the Area to generate FVectors for. {X,Y,Z}
		double m_Size[3] = { 0.0, 0.0, 0.0 };
		// Wrap the axis back to the start to have a repeating pattern? {X,Y,Z}
		bool m_Wrap[3] = { false, false, false };
		// Seed for random generation.
		UINT64 m_Seed = 0;
		
		// True when the Generator was already initialized or not the Generator was already initialized.
		bool m_IsInitialized = false;
	};

};