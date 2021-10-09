function [A] = adm(sig_in, Delta, td, ts)
    if (round(ts/td) >= 2)
        Nfac = round(ts/td);   
        xsig = downsample(sig_in,Nfac);
        Lxsig = length(xsig);
        Lsig_in = length(sig_in);
        A = zeros(Lsig_in); 
        cnt1 = 0;  
        cnt2 = 0; 
        sum = 0;
        for i=1:Lxsig
            
            if (xsig(i) == sum)
            elseif (xsig(i) > sum)
                if (cnt1 < 2)
                    sum = sum + Delta; 
                elseif (cnt1 == 2)
                    sum = sum + 2*Delta;    
                elseif (cnt1 == 3)
                    sum = sum + 4*Delta;    
                else
                    sum = sum + 8*Delta;   
                end
                if (sum < xsig(i))
                    cnt1 = cnt1 + 1;
                else
                    cnt1 = 0;
                end
            else
                if (cnt2 < 2)
                    sum = sum - Delta;
                elseif (cnt2 == 2)
                    sum = sum - 2*Delta;
                elseif (cnt2 == 3)
                    sum = sum - 4*Delta;
                else
                    sum = sum - 8*Delta;
                end
                if (sum > xsig(i))
                    cnt2 = cnt2 + 1;
                else
                    cnt2 = 0;
                end
            end
            ADMout(((i-1)*Nfac + 1):(i*Nfac)) = sum;
        end
    end
end