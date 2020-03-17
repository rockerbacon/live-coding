#pragma once

#include "connection_interface.h"
#include "message.h"

namespace chatter {
		class sender {
				private:
						connection_interface& interface;
				public:
						sender(connection_interface& interface) : interface(interface) {

						}

						void send(const message& msg) {
								interface.save(msg.contents, msg.destination);
						}
		};
}
