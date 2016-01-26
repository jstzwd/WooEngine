#include "TileLayer.h"

namespace Woo {
	namespace Graphics {
		TileLayer::TileLayer(Shader* shader) 
			:Layer(new BatchRenderer2D(), shader, Math::Matrice4::Orthographic(-5,5,5,-5,-1,1))
		{

		}

		TileLayer::~TileLayer()
		{
			
		}
	}
}