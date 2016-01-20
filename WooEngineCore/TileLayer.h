#pragma once

#include "Layer.h"
#include "BatchRenderer.h"

namespace Woo {
	namespace Graphics {
		class TileLayer : public Layer {
		public:
			TileLayer(Shader* shader);
			~TileLayer();
		};
	}
}
