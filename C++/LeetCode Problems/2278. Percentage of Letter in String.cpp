    int percentageLetter(string s, char letter) {
        int count=0;
        int size=s.size();
        for(int i=0;i<size;i++){
            if(s[i]==letter)   
                count++;
        }
        int percentage=(count*100/size);
        return percentage;
    }
