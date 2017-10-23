#include <Histogram.h>
void Histogram::record(double datum) {
    int bin = (int)((datum - min) / binWidth);
    if (bin < 0) {
        lowerOutlierCount++;
    } else if (bin >= binCount) {
        upperOutlierCount++;
    } else {
        count[bin]++;
    }
}
