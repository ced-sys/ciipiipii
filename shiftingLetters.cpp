/*You are given a string `s` of lowercase English letters and a 2D
integer array `shifts` where `shifts[i]=[start, end, direction]. For every `i`,
shift characters in `s` from the index `start` to the index `end` (inclusive) forward if
`direction=1`, or shift the characters backward if `direction=0`.

Shifting a character forward means replacing it with the next letter in the alphabet
(wrapping wround so that `z` becomes `a`). Similarly, shifting a character backward means replacing it with the 
previous letter in the alphabet (wrapping around so that 'a' becomes 'z').

return the final string after all such shifts to `s` are applied.*/

/*LOGIC

Use a difference array. To efficiently apply multiple overlapping shifts, use a difference array to track how much each 
character in the string should be shifted. Increment at start and decrement at end + 1 (if end+1 is within bounds). This approach ensure we 
efficiently manage overlapping shifts.

Apply shifts. Compute the cumulative shifts at each position by taking a prefix sum of the difference array. this will give the net shift for each character.

Handle direction. Convert backward shifts (`direction =0`) into negative values, and forward shifts (`directions=1`) into positive values.

Modulate the shift. Ensure the shifts wrap around the alphabet. Use the modulo operator (% 26 ) to ensure the shifts are within bonds.

Transform the string. For each character in `s`, calculate its new position in the alphabet based on the cumulative shift.*/

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        string result = s;
        
        for (const vector<int>& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            bool forward = shift[2] == 1;
            
            for (int i = start; i <= end; i++) {
                char& c = result[i];
                if (forward) {
                    c = (c - 'a' + 1) % 26 + 'a';
                } else {
                    c = (c - 'a' + 25) % 26 + 'a';
                }
            }
        }
        
        return result;
    }
};