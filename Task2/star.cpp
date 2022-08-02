#include "star.h"

Star::Star(QWidget* widget): polygon(widget)
{
    this->widget = widget;
    polygon::SetFills("(300;100)(330;150)(400;170)(330;190)(360;260)(300;210)(240;260)(270;190)(200;170)(270;150)");
}
