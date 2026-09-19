class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // Find the closest point to the circle's center within the rectangle
        int closestX = max(x1, min(xCenter, x2));
        int closestY = max(y1, min(yCenter, y2));
        
        // Calculate the distance between the circle's center and this closest point
        int distanceX = xCenter - closestX;
        int distanceY = yCenter - closestY;
        
        // If the squared distance is less than or equal to the squared radius, they overlap
        return (distanceX * distanceX + distanceY * distanceY) <= (radius * radius);
    }
};