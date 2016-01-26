#pragma once

#include "Layer.h"
#include "../Renderers/BatchRenderer.h"

namespace Woo {
	namespace Graphics {
		class TileLayer : public Layer {
		public:
			TileLayer(Shader* shader);
			~TileLayer();
		};
	}
}
