using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace TCLDemoRunner
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Beginning Test");
            var test = new InfoCheck();
            test.Test();
            Console.WriteLine("Finished Running.");
        }
    }

    //Test Runner
    class InfoCheck
    {
        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        public delegate int PassCallback(InfoNative info);
        [DllImport("CPPCode", CallingConvention = CallingConvention.Cdecl)]
        internal static extern int GetResponse(IntPtr handle, PassCallback cb);
        private readonly PassCallback _callback;
        public InfoCheck()
        {
            _callback = new InfoCheck.PassCallback(PassCB);
        }
        static private int PassCB(InfoNative info)
        {
            Console.WriteLine(info);
            return 1;
        }

        public void Test()
        {
            var ret = GetResponse((IntPtr)3151228115280 /*A basically random number used for testing*/, _callback);
            Console.WriteLine(ret);
        }
    }

    //The C# Version of the Struct

    [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Unicode)]
    public class InfoNative
    {

        public InfoNative()
        {
        }


        [MarshalAs(UnmanagedType.LPStr)]
        public string usercode;


        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 4, ArraySubType = UnmanagedType.U4)]
        public uint[] version;

        [MarshalAs(UnmanagedType.U8)]
        public long loading_timestamp;

        // Token: 0x040000AD RID: 173
        [MarshalAs(UnmanagedType.U1)]
        public byte already_activated;

        // Token: 0x040000AE RID: 174
        [MarshalAs(UnmanagedType.U1)]
        public byte auto_renew;

        // Token: 0x040000AF RID: 175
        [MarshalAs(UnmanagedType.U2)]
        public ushort review_status;

        // Token: 0x040000B0 RID: 176
        [MarshalAs(UnmanagedType.LPWStr)]
        public string company_name;

        // Token: 0x040000B1 RID: 177
        [MarshalAs(UnmanagedType.LPWStr)]
        public string contact_name;

        // Token: 0x040000B2 RID: 178
        [MarshalAs(UnmanagedType.LPStr)]
        public string email;

        // Token: 0x040000B3 RID: 179
        [MarshalAs(UnmanagedType.LPStr)]
        public string telephone;

        // Token: 0x040000B4 RID: 180
        [MarshalAs(UnmanagedType.LPStr)]
        public string country_id;

        // Token: 0x040000B5 RID: 181
        [MarshalAs(UnmanagedType.LPStr)]
        public string country_name;

        // Token: 0x040000B6 RID: 182
        [MarshalAs(UnmanagedType.LPStr)]
        public string admin_email;

        // Token: 0x040000B7 RID: 183
        [MarshalAs(UnmanagedType.LPWStr)]
        public string reseller_name;

        // Token: 0x040000B8 RID: 184
        [MarshalAs(UnmanagedType.U8)]
        public long expiration_time;

        // Token: 0x040000B9 RID: 185
        [MarshalAs(UnmanagedType.I4)]
        public int max_connections;

        // Token: 0x040000BA RID: 186
        [MarshalAs(UnmanagedType.I4)]
        public int max_chan;

        // Token: 0x040000BB RID: 187
        [MarshalAs(UnmanagedType.U8)]
        public long maintenance_expiration_date;

        // Token: 0x040000BC RID: 188
        [MarshalAs(UnmanagedType.U8)]
        public long support_expiration_date;

        // Token: 0x040000BD RID: 189
        [MarshalAs(UnmanagedType.I4)]
        public int max_wm_connections;

        // Token: 0x040000BE RID: 190
        [MarshalAs(UnmanagedType.U8)]
        public long last_erp_check_date;
    }
}
