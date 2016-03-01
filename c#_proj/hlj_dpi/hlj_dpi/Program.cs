using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;

namespace TextDataCreate
{
    class Program
    {
        static void Main(string[] args)
        {
            //Parse();
            CreateData();
        }

        static void CreateData()
        {
            string[] urls = {                                                                 
                                "zf.naimei.com/bottom/imagestui/jweixin-1.js",                                
                                "rr.spgz.net/item/Content/js/jquery-1.7.1.min.js",
                                "isdspeed.qq.com/cgi-bin/r.cgi?1=1667&flag1=7832&flag2=47&flag3=3&ts=1451528635207",       
                                "wireless.mapbar.com",
                                "push.mobile.kugou.com/v1/pull?apikey=and10&device=5ba2a08a05e24b1ca28e32c9f615cdf0&sign=aef2fc2ba184a48c04c134092ee8a757&_t=1451528644",                                
                                "api.ad.xiaomi.com",
                                "p.l.qq.com/p?oid=55&exp=0&pv_type=0&loid=1&seq=3&index=1&chid=0&channel=100101&loc=QQlive_APPWeb_MB_XXL&appversion=151202&pf=aphone&server_data=&dtype=3&data=AS64N6HIoeOll5WjixZ%2B7x1MJf%2FbEoPTmb4cSNiQPXGIB%2FbOFT4QR2S%2BcPfBGLEOye89ArEbHL0G74flTijQJnjTuSaMjUvk7jFyp1bGZzHA2D9nECSd2Q%2FZsDmVX3EllTrEs0Pjb114IF%2FdUb8k98Ro%2BTqkS6p%2FT4Ga2pBRa3wScCZofooILJpJyPxAsCgW5VBdRwD8wla%2FsAN7UEiRPQleOZLuSp7EkcPT%2FGYCznAoz93LtMbHkOVeQgdek7pGNKLoPrd7vJP2oZwCkttTQ4vfM%2BbRisOsx9uXRnrDODIFLXsJBzzpzyQjl0U1VL1YaCbL7xPWI%2",
                                "p?oid=2457809&cid=1250759&loid=0&exp=0&pv_type=1&index=1&seq=1&pvLimit=-1&pvFcs=-1&chid=0&channel=2015-12-31&loc=QQlive_APPWeb_Phone_Splash&soid=7D%2FL2honVoRp1gGg9wCC%2Bj8WAfqg&dtype=3&server_data=&ping_data=dXNlcl9pbmZvPW9CM2pnVGs2RXhhNQ%3D%3D&appversion=151202&pf=aphone&data=AS64N6HIoeOll5WjixZ%2B7x1MJf%2FbEoPTmb4cSNiQPXGIB%2FbOFT4QR2S%2BcPfBGLEOye89ArEbHL0G74flTijQJnjTuSaMjUvk7jFyp1bGZzHA2D9nECSd2Q%2FZsDmVX3EllTrEs0Pjb114IF%2FdUb8k98Ro%2BTqkS6p%2FT4Ga2pBRa3wScCZofooILJpJyPxAsCgW5VBdRwD8wla%2"
                            };
            long phone = 13693458823;
            long startTime = 1451528558080;
            long endTime = 1451528558111;
            string url = "zf.naimei.com/bottom/imagestui/jweixin-1.js";
            string appType = "1";
            string appSubType = "9";
            long ulData = 872;
            long dlData = 108462;
            string netMode = "3";
            string apn = "cmnet";
            long imei = 866357026773306;
            string busiType = "103";

            long count = 10000002;

            string path = @"G:\!!Work_Git\myself\Proj\dpi\TextData\";
            long temp = long.Parse(DateTime.Now.ToString("yyyyMMddHHmmss"));
            string dataFile = string.Format(@"{0}{1}.txt", path, temp);
            for (long i = 2; i < count; i++)
            {
                Random random = new Random();
                string line = string.Format(@"{0}|{1}|{2}|{3}|{4}|{5}|{6}|{7}|{8}|{9}|{10}|{11}{12}",
                    phone++, startTime++, endTime++, urls[random.Next(8)], appType, appSubType, ulData++, dlData++, netMode, apn, imei++, busiType, System.Environment.NewLine);
                File.AppendAllText(dataFile, line, Encoding.Default);

                if (i % 1000000 == 1)
                {
                    dataFile = string.Format(@"{0}{1}.txt", path, long.Parse(DateTime.Now.ToString("yyyyMMddHHmmss")));
                }
            }
        }

        static void Parse()
        {
            string log = string.Format(@"{0}\test.log", AppDomain.CurrentDomain.BaseDirectory.TrimEnd('\\'));
            string path = @"G:\!!Work_Git\myself\Proj\dpi\TextData\";
            List<string> files = new List<string>(Directory.GetFiles(path));
            foreach (string file in files)
            {
                Stopwatch watch = new Stopwatch();
                watch.Start();

                using (StreamReader sr = new StreamReader(file))
                {
                    while (!sr.EndOfStream)
                    {
                        string line = sr.ReadLine();
                    }
                }

                watch.Stop();
                string theSecond = watch.Elapsed.TotalSeconds.ToString();
                string lg = string.Format(@"{0} : {1}秒{2}", file, theSecond, System.Environment.NewLine);
                File.AppendAllText(log, lg, Encoding.Default);
            }
        }
    }
}
