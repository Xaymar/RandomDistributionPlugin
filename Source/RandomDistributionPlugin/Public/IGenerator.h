#include "RandomDistributionPluginPrivatePCH.h"

namespace RandomDistributionPlugin {
	class IGenerator {
	protected:
		// Size of the Area to generate FVectors for. {X,Y,Z}
		double* m_Size;
		// Wrap the axis back to the start to have a repeating pattern? {X,Y,Z}
		bool* m_Wrap;
		// Seed for random generation.
		UINT64 m_Seed = 0;
		// True when the Generator was already initialized or not the Generator was already initialized.
		bool m_IsInitialized = false;

	public:
		IGenerator();
		virtual ~IGenerator();

		/**
		 * Returns a shared copy of the Size array.
		 *
		 * @return std::shared_ptr<std::array<double, 3>>
		 */
		virtual TSharedPtr<double> GetSize();

		/**
		 * Changes the Size of the generated area.
		 *
		 * @param  pWidth Width of the generated area.
		 * @param  pHeight Height of the generated area.
		 * @param  pDepth Depth of the generated area.
		 * @return void
		 */
		virtual void SetSize(double pWidth, double pHeight, double pDepth);

		/**
		 * Retrieves the Width of the generated area.
		 *
		 * @return double
		 */
		virtual double GetWidth();

		/**
		 * Helper method to quickly change the Width of the generated area.
		 *
		 * @param  pWidth Width of the generated area.
		 * @return void
		 */
		virtual void SetWidth(double pWidth);

		/**
		* Retrieves the Height of the generated area.
		*
		* @return double
		*/
		virtual double GetHeight();

		/**
		* Helper method to quickly change the Height of the generated area.
		*
		* @param  pHeight Height of the generated area.
		* @return void
		*/
		virtual void SetHeight(double pHeight);

		/**
		* Retrieves the Depth of the generated area.
		*
		* @return double
		*/
		virtual double GetDepth();

		/**
		* Helper method to quickly change the Depth of the generated area.
		*
		* @param  pDepth Depth of the generated area.
		* @return void
		*/
		virtual void SetDepth(double pDepth);

		/** 
		 * Returns a shared copy of the Wrap array.
		 *
		 * @return std::shared_ptr<bool*>
		 */
		virtual TSharedPtr<bool> GetWrap();

		/** 
		 * Changes how the generated area repeats.
		 *
		 * @param  pWrapX Repeat the area on the X axis.
		 * @param  pWrapY Repeat the area on the Y axis.
		 * @param  pWrapZ Repeat the area on the Z axis.
		 * @return void
		 */
		virtual void SetWrap(bool pWrapX, bool pWrapY, bool pWrapZ);

		/** 
		 * Retrieves the seed used to generate points.
		 *
		 * @return int
		 */
		virtual int GetSeed();

		/** 
		 * Sets the seed used to generate points.
		 *
		 * @param  pSeed
		 * @return void
		 */
		virtual void SetSeed(int pSeed);

		/** 
		 * Reserves any memory that is required to generate and store the created points.
		 *
		 * @return void
		 */
		virtual void Initialize() = 0;

		/** 
		 * Releases any reserved memory from the generator.
		 *
		 * @return void
		 */
		virtual void Deinitialize() = 0;

		/** 
		 * Generates a new set of FVectors and returns them.
		 *
		 * @param  pIterations How many Iterations should be gone through.
		 * @return FVector*
		 */
		virtual TSharedPtr<TDoubleLinkedList<TSharedPtr<FVector>>> Generate(UINT64 pIterations) = 0;

		/** 
		 * Retrieves all currently generated points
		 *
		 * Long Description Here,
		 * May Be Multiple Lines Long.
		 *
		 * @return FVector*
		 */
		virtual TSharedPtr<TDoubleLinkedList<TSharedPtr<FVector>>> Retrieve() = 0;

	};

};