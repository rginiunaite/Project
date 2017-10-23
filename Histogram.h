class Histogram {
  public:
    // Pick whichever constructor feels more natural to you
    Histogram(double min, double max, int numberOfBins);
    Histogram(double min, double max, double binWidth);

    void record(double datum);
    int bins() const;                    // Get the number of bins
    int count(int bin) const;            // Get the number of data points in some bin
    int countLowerOutliers() const;      // Get count of values below the minimum
    int countUpperOutliers() const;      // Get count of values at or above the maximum
    double lowerBound(int bin) const;    // Get the inclusive lower bound of a bin
    double upperBound(int bin) const;    // Get the exclusive upper bound of a bin

    virtual ~Histogram();

  private:
    double binWidth;
    int binCount;
    int lowerOutlierCount, upperOutlierCount;
    int counts[];
};
