{
ID: mfs.dev2
PROG: prime3
LANG: PASCAL
}
program prime3;
type
  matrix=array[1..5,1..5]of integer;
var
  sum,tmp,i,fa,j,k,l,m,n,a11,a12,a13,a14,a15,a21,a22,a23,a24,a25,a31,a32,a33,a34,a35,a41,a42,a43,a44,a45,a51,a52,a53,a54,a55:longint;
  prime:array[0..99999]of boolean;
  f:matrix;
  temp:array[1..10000]of matrix;
  ans:array[1..10000]of string[25];
  ar:boolean;
 
procedure getprimes;
var
  i,j:longint;
begin
  fillchar(prime,sizeof(prime),true);
  prime[1]:=false;
  prime[0]:=false;
  for i:=2 to 99999 do
    if prime[i] then
      for j:=2 to 99999 div i do prime[i*j]:=false;
end;
 
function check(a1,a2,a3,a4,a5:longint):Boolean;
var
  i,j:longint;
begin
  if a1<0 then exit(false);
  if a2<0 then exit(false);
  if a3<0 then exit(false);
  if a4<0 then exit(false);
  if a5<0 then exit(false);
  if a1>10 then exit(false);
  if a2>10 then exit(false);
  if a3>10 then exit(false);
  if a4>10 then exit(false);
  if a5>10 then exit(false);
  j:=a1*10000+a2*1000+a3*100+a4*10+a5;
  if j<10000 then exit(false);
  if not prime[j] then exit(false);
  exit(true);
end;
 
function judge(t:matrix):boolean;
var
  i,j:longint;
begin
  for i:=1 to 5 do if not check(t[i,1],t[i,2],t[i,3],t[i,4],t[i,5]) then exit(false);
  for i:=1 to 5 do if not check(t[1,i],t[2,i],t[3,i],t[4,i],t[5,i]) then exit(false);
  if not check(t[1,1],t[2,2],t[3,3],t[4,4],t[5,5]) then exit(false);
  if not check(t[5,1],t[4,2],t[3,3],t[2,4],t[1,5]) then exit(false);
  exit(true);
end;
 
procedure print(x:longint);
var
  y:matrix;
  i,j:longint;
begin
  for i:=1 to 5 do
    for j:=1 to 5 do val(ans[x,(i-1)*5+j],y[i,j]);
  if not judge(y) then exit;
 
  if ar then writeln;
  ar:=true;
  for i:=1 to 25 do
  begin
    write(ans[x,i]);
    if i mod 5=0 then writeln;
  end;
end;
 
procedure transform(t:matrix);
var
  ch:string;
  i,j:longint;
begin
  inc(fa);
  ans[fa]:='';
  for i:=1 to 5 do
    for j:=1 to 5 do
    begin
      str(t[i,j],ch);
      ans[fa]:=ans[fa]+ch;
    end;
end;
 
 
function bigger(a,b:string):boolean;
var
  i:longint;
begin
  for i:=1 to 25 do
  begin
    if a[i]>b[i] then exit(true);
    if a[i]<b[i] then exit(false);
  end;
  exit(false);
end;
 
function smaller(a,b:string):boolean;
var
  i:longint;
begin
  for i:=1 to 25 do
  begin
    if a[i]<b[i] then exit(true);
    if a[i]>b[i] then exit(false);
  end;
  exit(false);
end;
 
procedure qs(l,r:longint);
var
  i,j:longint;
  mx,y:string;
begin
  i:=l;
  j:=r;
  mx:=ans[(l+r) div 2];
  while i<=j do
  begin
    while smaller(ans[i],mx) do inc(i);
    while bigger(ans[j],mx) do dec(j);
    if i<=j then
    begin
      y:=ans[i];
      ans[i]:=ans[j];
      ans[j]:=y;
      inc(i);
      dec(j);
    end;
  end;
  if (i<r) then qs(i,r);
  if (l<j) then qs(l,j);
end;
 
 
begin
  assign(input,'prime3.in');
  reset(input);
  assign(output,'prime3.out');
  rewrite(output);
 
  tmp:=0;
  getprimes;
 
  readln(sum,a11);
  f[1,1]:=a11;
 
  for a22:=0 to 9 do {2}
  begin
    f[2,2]:=a22;
 
    for a44:=0 to 9 do  {3}
    begin
      f[4,4]:=a44;
 
      for a55:=1 to 9 do if (odd(a55))and(a55 mod 5<>0) then  {4}
      begin
        f[5,5]:=a55;
 
        a33:=sum-a11-a22-a44-a55;
        f[3,3]:=a33;
        if not check(a11,a22,a33,a44,a55) then continue;
 
 
        for a15:=1 to 9 do if (odd(a15))and(a15 mod 5<>0) then  {5}
        begin
          f[1,5]:=a15;
 
          for a24:=0 to 9 do    {6}
          begin
            f[2,4]:=a24;
 
            for a51:=1 to 9 do if (odd(a51))and(a51 mod 5<>0) then {7}
            begin
              f[5,1]:=a51;
 
              a42:=sum-a15-a24-a33-a51;
              f[4,2]:=a42;
              if not check(a51,a42,a33,a24,a15) then continue;
 
              for a25:=1 to 9 do if (odd(a25))and(a25 mod 5<>0) then  {8}
              begin
                f[2,5]:=a25;
 
                for a45:=1 to 9 do if (odd(a45))and(a45 mod 5<>0) then   {9}
                begin
                  f[4,5]:=a45;
 
                  a35:=sum-a15-a25-a45-a55;
                  f[3,5]:=a35;
                  if (a35 in [0,2,4,5,6,8])or(not check(a15,a25,a35,a45,a55)) then continue;
 
                  for a52:=1 to 9 do if (odd(a52))and(a52 mod 5<>0) then    {10}
                  begin
                    f[5,2]:=a52;
 
                    for a54:=1 to 9 do if (odd(a54))and(a54 mod 5<>0) then     {11}
                    begin
                      f[5,4]:=a54;
 
                      a53:=sum-a51-a52-a54-a55;
                      f[5,3]:=a53;
                      if (not check(a51,a52,a53,a54,a55))then continue;
 
                      for a12:=1 to 9 do      {12}
                      begin
                        f[1,2]:=a12;
 
                        a32:=sum-a12-a22-a42-a52;
                        f[3,2]:=a32;
                        if not check(a12,a22,a32,a42,a52) then continue;
 
                        for a14:=1 to 9 do        {13}
                        begin
                          f[1,4]:=a14;
 
                          a13:=sum-a11-a12-a14-a15;
                          f[1,3]:=a13;
                          if (a13=0)or(not check(a11,a12,a13,a14,a15)) then continue;
 
                          a34:=sum-a14-a24-a44-a54;
                          f[3,4]:=a34;
                          if not check(a14,a24,a34,a44,a54) then continue;
 
                          a31:=sum-a32-a33-a34-a35;
                          f[3,1]:=a31;
                          if (a31=0)or(not check(a31,a32,a33,a34,a35)) then continue;
 
                          for a21:=1 to 9 do          {14}
                          begin
                            f[2,1]:=a21;
 
                            a23:=sum-a21-a22-a24-a25;
                            f[2,3]:=a23;
                            if not check(a21,a22,a23,a24,a25) then continue;
 
                            a41:=sum-a11-a21-a31-a51;
                            f[4,1]:=a41;
                            if (a41=0)or(not check(a11,a21,a31,a41,a51)) then continue;
 
                            a43:=sum-a41-a42-a44-a45;
                            f[4,3]:=a43;
                            if not check(a41,a42,a43,a44,a45) then continue;
 
                            if not check(a13,a23,a33,a43,a53) then continue;
 
                            inc(tmp);
                            temp[tmp]:=f;
                          end;{f[2,1]}
 
                        end;{f[1,4]}
 
                      end;{f[1,2]}
 
                    end;{f[5,4]}
 
                  end;{f[5,2]}
 
                end;{f[4,5]}
 
              end;{f[2,5]}
 
            end;{f[5,1]}
 
          end;{f[2,4]}
 
        end;{f[1,5]}
 
      end;{f[5,5]}
 
    end;{f[4,4]}
 
  end;{f[2,2]}
  fa:=0;//final answer
  for i:=1 to tmp do
    if judge(temp[i]) then transform(temp[i]);
  qs(1,fa);
  ar:=false;
  for i:=1 to fa do
    print(i);
  if not ar then writeln('NONE');
  close(output);
  close(input);
end.