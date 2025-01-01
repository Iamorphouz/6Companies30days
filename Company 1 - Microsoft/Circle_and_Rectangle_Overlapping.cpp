class Solution
{
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2)
    {
        int nearestX;
        if (xCenter < x1)
            nearestX = x1;
        else if (xCenter > x2)
            nearestX = x2;
        else
            nearestX = xCenter; // xCenter is either equal to (x1 or x2) or in between x1 & x2

        int nearestY;
        if (yCenter < y1)
            nearestY = y1;
        else if (yCenter > y2)
            nearestY = y2;
        else
            nearestY = yCenter; // yCenter is either equal to (y1 or y2) or in between y1 & y2

        // distance from nearest (X,Y) on rectangle must be less than or equal to radius of circle
        int distFromCircle = (nearestX - xCenter) * (nearestX - xCenter) + (nearestY - yCenter) * (nearestY - yCenter);

        return distFromCircle <= radius * radius;
    }
};