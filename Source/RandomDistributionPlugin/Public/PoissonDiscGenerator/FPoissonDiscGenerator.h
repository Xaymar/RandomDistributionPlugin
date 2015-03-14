#include "RandomDistributionPluginPrivatePCH.h"
#include "IGenerator.h"

namespace RandomDistributionPlugin {
	class FPoissonDiscGenerator : IGenerator {
	private:
		FRandomStream m_RandomStream;

		// List of already generated FVectors.
		TDoubleLinkedList<TSharedPtr<FVector>> m_Points;
		// List of still valid points.
		TDoubleLinkedList<TSharedPtr<FVector>> m_WorkablePoints;

		double m_Distance = 1.0;
		double m_CellSize = 0.0;
		// Amount of cells required for storage.
		UINT32 m_Cells[3];
		UINT64 m_CellTotal = 0;
		// 3D-Array of generated FVectors.
		TSharedPtr<FVector*>* m_CellGrid = NULL;
	public:
		FPoissonDiscGenerator();
		virtual ~FPoissonDiscGenerator();

		virtual double GetDistance();

		virtual void SetDistance(double pDistance);

		virtual void Initialize();

		virtual void Deinitialize();

		virtual TSharedPtr<TDoubleLinkedList<TSharedPtr<FVector>>> Generate(UINT64 pIterations);

		virtual TSharedPtr<TDoubleLinkedList<TSharedPtr<FVector>>> Retrieve();

	};
}