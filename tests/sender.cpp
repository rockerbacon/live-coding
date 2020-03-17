#include <assertions-test/test.h>

#include <sender.h>
#include <message.h>

using namespace chatter;
using namespace std;

class stub_interface : connection_interface {
	public:
		string message;
		string destination;

		void send (const string& msg, const string& dst) {
			message = msg;
			destination = dst;
		}
}

tests {
		test_suite("when sending messages to the interface") {
				test_case("should send correct message parameters") {
					stub_interface interface;
					sender s(interface);

					s.send(message{
						"this is a test message",
						"nick"
					})

					assert(interface.message, ==, "this is a test message");
					assert(interface.destination, ==, "nick");
				};
		}
}
