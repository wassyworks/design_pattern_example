#ifndef _LOGGER_H_
#define _LOGGER_H_
#include "xml_exporter.h"
namespace adapter {
	class Logger : public XmlExporter {
	public:
		virtual void Logging(const std::string& message) const {
			std::cout << ToXml(message) << std::endl;
		};
	};
}

#endif // !_LOGGER_H_
