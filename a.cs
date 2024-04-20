Chio Alexey, [11.02.2024 16:44]
//Go Chio
using System.Collections.Generic;
using System.Numerics;
using System.Text;
using System.IO;
using System.Linq;
using System.Diagnostics.CodeAnalysis;
using System.Xml;
using System.IO.Pipes;
using System;
using System.ComponentModel.Design;
using System.Diagnostics.Metrics;



public class Program
{

    public static void Main(string[] args)
    {
        CB();
        int count = ReadInt();
        while (count-- > 0)
            Solve();

        CE();
    }


    public static void Solve()
    {

        // var s = ReadStream().ReadLine().Split();
        // WriteStream().Write("++");


       
        
        
        
        /* 
        int[] nm = ReadIntArray();

        int n = nm[0];//строки
        int m = nm[1];//столбцы

        char[][] desc = new char[n][];

        int an = -1;
        int am = -1;
        int bn = -1;
        int bm = -1;
        for (int i =0;i<n;i++){
            desc[i] = ReadLine().ToCharArray();
            if (an == -1)
            {
                var t = Array.IndexOf(desc[i], 'A');
                if (t != -1) { an = i; am = t; }
            }

            if (bn == -1)
            {
                var r = Array.IndexOf(desc[i], 'B');
                if (r != -1) { bn = i; bm = r; }
            }
        }
        if (an < bn) {
            if (an % 2 == 1) { desc[an - 1][am] = 'a'; an--; }
            if (bn % 2 == 1) { desc[bn + 1][bm] = 'b'; bn++; }
        } else {
            if (an % 2 == 1) { desc[an + 1][am] = 'a'; an++; }
            if (bn % 2 == 1) { desc[bn - 1][bm] = 'b'; bn--; }

        }

        if (am < bm) {
            for (int i = 0; i < am; i++) { desc[an][i] = 'a'; }
            for (int i = 0; i < an; i++) { desc[i][0]='a'; }

            for (int i = bm+1; i <m; i++) { desc[bn][i] = 'b'; }
            for (int i = bn+1; i < n; i++) { desc[i][m-1] = 'b'; }

        }
        else {
            for (int i = 0; i < bm; i++) { desc[bn][i] = 'b'; }
            for (int i = 0; i < bn; i++) { desc[i][0] = 'b'; }

            for (int i = am + 1; i < m; i++) { desc[an][i] = 'a'; }
            for (int i = an + 1; i < n; i++) { desc[i][m - 1] = 'a'; }
        }

        for (int i = 0; i < n; i++) {
            Print(string.Join("",desc[i]));
        }
        */

        /*
        // M - запускает
        //R - перезапускает
        //С - отмена
        //D - завершает




        string ex = ReadLine();
        int n = ex.Length;
        if (ex[0] != 'M') { Print("NO"); return; }
        //if (ex[n - 1] != 'D') { Print("NO");return; }
        int state = 1;
        for (int i = 1; i < n; i++) {

            switch (state)
            {
                case 0: //остановлена D
                    if (ex[i] == 'M') { state = 1; } else { Print("NO"); return; }


                    break;
                case 1://запущена
                    if (ex[i] == 'C') { state = 2; }
                    else
                    if (ex[i] == 'R') { state = 3; }
                    else
                    if (ex[i] == 'D') { state = 0; } else { Print("NO"); return; }

                    break;
                case 2://отменена C
                    if (ex[i] == 'M') { state = 1; } else { Print("NO"); return; }
                    break;



                case 3: //перезапущена R
                    if (ex[i] == 'C') { state = 0; } else { Print("NO"); return; }
                    break;
            }
        }
        if (state == 0) { Print("YES"); } else { Print("NO"); }


        */


       
         int[] np = ReadIntArray();
        int n = np[0];
        int p = np[1];

        int[] a = new int[n];
        int sumtot = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            a[i] = ReadInt();
            sumtot += a[i]*p/100;
            sum = sum + a[i];
        }



        var x = p * sum * 1.0 / 100 - sumtot;
        var z = x.ToString("0.00");
    Print(Regex.Replace(z, @"\,", @"\."));


       

    }

/*
    using var input = new StreamReader(Console.OpenStandardInput());
using var output = new StreamWriter(Console.OpenStandardOutput());

var s = input.ReadLine().Split();
int a = int.Parse(s[0]);
int b = int.Parse(s[1]);
output.Write(a + b);
    */

    public static StreamReader ReadStream() { return new StreamReader(Console.OpenStandardInput());  }
    public static StreamWriter WriteStream() { return new StreamWriter(Console.OpenStandardOutput()); }


public static string YES { get { return "YES"; } }
    public static string NO { get { return "NO"; } }
    public static string Yes { get { return "Yes"; } }
    public static string No { get { return "No"; } }
    public static void Print(object t) { Console.WriteLine(t); }
    public static void Print(params object[] array) { StringBuilder sb = new StringBuilder(); for (int i = 0; i < array.Length; i++) { sb.Append(array.GetValue(i)); sb.Append(' '); } Print(sb); }
    public static void Print(Array array) { StringBuilder sb = new StringBuilder(); for (int i = 0; i < array.Length; i++) { sb.Append(array.GetValue(i)); sb.Append(' '); } Print(sb); }
    public static void CB() { Console.SetOut(new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false }); }
    public static void CE() { Console.Out.Flush(); }
    public static string ReadLine() { return Console.ReadLine() ?? ""; }
    public static int ReadInt() { return int.Parse(ReadLine()); }
    public static long ReadLong() { return long.Parse(ReadLine()); }
    public static int[] ReadIntArray() { return ReadLine().Split().Select(int.Parse).ToArray(); }
    public static List<int> ReadIntList() { return ReadLine().Split().Select(int.Parse).ToList(); }
    public static long[] ReadLongArray() { return ReadLine().Split().Select(long.Parse).ToArray(); }
}