#include "RandomDistributionPluginPrivatePCH.h"
#include "IGenerator.h"

using namespace RandomDistributionPlugin;

IGenerator::IGenerator() {
	this->m_Size = new double[3];
	this->m_Wrap = new bool[3];
}

IGenerator::~IGenerator() {
	delete this->m_Wrap;
	delete this->m_Size;
}

void IGenerator::SetSize(double pWidth, double pHeight, double pDepth) {
	this->m_Size[0] = pWidth;
	this->m_Size[1] = pHeight;
	this->m_Size[2] = pDepth;
}

TSharedPtr<double> IGenerator::GetSize() {
	double* copyArray = new double[3];
	memcpy(copyArray, this->m_Size, sizeof(double[3]));
	return MakeShareable<double>(copyArray);
}

void RandomDistributionPlugin::IGenerator::SetWidth(double pWidth) {
	m_Size[0] = pWidth;
}

double RandomDistributionPlugin::IGenerator::GetWidth() {
	return m_Size[0];
}

void RandomDistributionPlugin::IGenerator::SetHeight(double pHeight) {
	m_Size[1] = pHeight;
}

double RandomDistributionPlugin::IGenerator::GetHeight() {
	return m_Size[1];
}

void RandomDistributionPlugin::IGenerator::SetDepth(double pDepth) {
	m_Size[2] = pDepth;
}

double RandomDistributionPlugin::IGenerator::GetDepth() {
	return m_Size[2];
}


void RandomDistributionPlugin::IGenerator::SetWrap(bool pWrapX, bool pWrapY, bool pWrapZ) {
	this->m_Wrap[0] = pWrapX;
	this->m_Wrap[1] = pWrapY;
	this->m_Wrap[2] = pWrapZ;
}

TSharedPtr<bool> RandomDistributionPlugin::IGenerator::GetWrap() {
	bool* copyArray = new bool[3];
	memcpy(copyArray, this->m_Wrap, sizeof(bool[3]));
	return MakeShareable<bool>(copyArray);
}

void RandomDistributionPlugin::IGenerator::SetSeed(int pSeed) {
	m_Seed = pSeed;
}

int RandomDistributionPlugin::IGenerator::GetSeed() {
	return m_Seed;
}