#pragma once

#include <qobjectdefs.h>

class DirectionGadget
{
    Q_GADGET

public:

    enum Type
    {
      North = 0,
      East  = 90,
      South = 180,
      West  = 270
    };
    Q_ENUM(Type)

    static void registerQmlTypes(const char *uri, int majorVersion, int minorVersion);
};

typedef DirectionGadget::Type DirectionType;
