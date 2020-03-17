#pragma once

#include <string>

namespace chatter {
		class connection_interface {
				public:
						virtual void save (const std::string& msg, const std::string& dst) = 0;
		};
}
