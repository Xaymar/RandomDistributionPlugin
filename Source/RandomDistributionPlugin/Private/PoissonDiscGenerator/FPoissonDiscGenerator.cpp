#include "RandomDistributionPluginPrivatePCH.h"
#include "FPoissonDiscGenerator.h"

using namespace RandomDistributionPlugin;

FPoissonDiscGenerator::FPoissonDiscGenerator() {

}
FPoissonDiscGenerator::~FPoissonDiscGenerator() {

}

double FPoissonDiscGenerator::GetDistance() {
	return this->m_Distance;
}

void FPoissonDiscGenerator::SetDistance(double pDistance) {
	this->m_Distance = pDistance;
}

void RandomDistributionPlugin::FPoissonDiscGenerator::Initialize() {
	// Deinitialize before trying to initialize again.
	if (this->m_IsInitialized)
		this->Deinitialize();
	
	// Reinitialize random stream.
	this->m_RandomStream.Initialize(this->m_Seed);

	// Calculate cells.
	m_CellSize = this->m_Distance / sqrt(2.0);
	for (int i = 0; i < 3; i++) {
		m_Cells[i] = ceil(m_Size[i] / m_CellSize);
		if (m_Cells[i] < 1)
			m_Cells[i] = 1;
	}

	// Reserve a continuous block of memory.
	m_CellTotal = m_Cells[0] * m_Cells[1] * m_Cells[2];
	m_CellGrid = new TSharedPtr<FVector*>[m_CellTotal];

	m_IsInitialized = true;
}

void RandomDistributionPlugin::FPoissonDiscGenerator::Deinitialize() {
	if (m_IsInitialized) {
		// Empty Lists.
		this->m_WorkablePoints.Empty();
		this->m_Points.Empty();

		// Free memory.
		if (m_CellGrid) {
			for (UINT64 i = 0; i < m_CellTotal; i++) {
				if (m_CellGrid[i].IsValid())
					m_CellGrid[i].Reset();
			}
			delete m_CellGrid;
			m_CellGrid = NULL;
		}
		m_CellTotal = 0;

		// Reset cells.
		m_Cells[0] = 0;
		m_Cells[1] = 0;
		m_Cells[2] = 0;
		m_CellSize = 0.0;

		m_IsInitialized = false;
	}
}

TSharedPtr<TDoubleLinkedList<TSharedPtr<FVector>>> RandomDistributionPlugin::FPoissonDiscGenerator::Generate(UINT64 pIterations) {
	return MakeShareable<TDoubleLinkedList<TSharedPtr<FVector>>>(new TDoubleLinkedList<TSharedPtr<FVector>>());
}

TSharedPtr<TDoubleLinkedList<TSharedPtr<FVector>>> RandomDistributionPlugin::FPoissonDiscGenerator::Retrieve() {
	return MakeShareable<TDoubleLinkedList<TSharedPtr<FVector>>>(new TDoubleLinkedList<TSharedPtr<FVector>>());
}