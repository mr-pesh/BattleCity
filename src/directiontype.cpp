#include "directiontype.h"
#include <qqml.h>

void DirectionGadget::registerQmlTypes(const char *uri, int majorVersion, int minorVersion)
{
    qRegisterMetaType<DirectionType>();
    qmlRegisterUncreatableType<DirectionGadget>(
        uri, majorVersion, minorVersion, "Direction",
        "Direction is the enum type and can't be instantiated");
}
