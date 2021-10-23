<script>

// Javascript program to find lexicographically next
// string

function nextWord(s)
{
	// If string is empty.
	if (s == "")
		return "a";

	// Find first character from right
	// which is not z.
	
	var i = s.length - 1;
	while (s[i] == 'z' && i >= 0)
		i--;

	// If all characters are 'z', append
	// an 'a' at the end.
	if (i == -1)
		s = s + 'a';

	// If there are some non-z characters
	else
		s[i] = String.fromCharCode(s[i].charCodeAt(0)+1);

	return s.join('');
}

// Driver code
var str = "samez".split('');
document.write( nextWord(str));

// This code is contributed by noob2000.
</script>
