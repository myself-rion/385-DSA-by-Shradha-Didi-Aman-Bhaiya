int maxArea(vector<int> &height)
{
    int left = 0, right = height.size() - 1, res = 0;

    while (left < right)
    {
        res = max(res, (right - left) * min(height[left], height[right])); //right-left= width, min height will be the length of the water rectangle

        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    return res;
}