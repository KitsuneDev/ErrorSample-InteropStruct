#include "stdafx.h"
#include <apiquery2.h>

struct InfoNative
{
	// Token: 0x06000025 RID: 37 RVA: 0x000021CC File Offset: 0x000003CC


	// Token: 0x040000AA RID: 170


	LPSTR usercode;

	// Token: 0x040000AB RID: 171
	//[MarshalAs(UnmanagedType.ByValArray, SizeConst = 4, ArraySubType = UnmanagedType.U4)]
	unsigned int* version[4];


	unsigned long first_activation_ts;

	// Token: 0x040000AD RID: 173

	BYTE already_activated;



	// Token: 0x040000AE RID: 174
	BYTE auto_renew;

	// Token: 0x040000AF RID: 175
	//[MarshalAs(UnmanagedType.U2)]
	unsigned short review_status;

	// Token: 0x040000B0 RID: 176
	//[MarshalAs(UnmanagedType.LPWStr)]
	LPWSTR company_name;

	// Token: 0x040000B1 RID: 177
	//[MarshalAs(UnmanagedType.LPWStr)]
	LPWSTR contact_name;

	// Token: 0x040000B2 RID: 178
	//[MarshalAs(UnmanagedType.LPStr)]
	LPSTR email;

	// Token: 0x040000B3 RID: 179
	//[MarshalAs(UnmanagedType.LPStr)]
	LPSTR telephone;

	// Token: 0x040000B4 RID: 180
	//[MarshalAs(UnmanagedType.LPStr)]
	LPSTR country_id;

	// Token: 0x040000B5 RID: 181
	//[MarshalAs(UnmanagedType.LPStr)]
	LPSTR country_name;

	// Token: 0x040000B6 RID: 182
	//[MarshalAs(UnmanagedType.LPStr)]
	LPSTR admin_email;

	// Token: 0x040000B7 RID: 183
	//[MarshalAs(UnmanagedType.LPWStr)]
	LPWSTR reseller_name;

	// Token: 0x040000B8 RID: 184
	//[MarshalAs(UnmanagedType.U8)]
	unsigned long expiration_date_ts;

	// Token: 0x040000B9 RID: 185
	//[MarshalAs(UnmanagedType.I4)]
	int max_connections;

	// Token: 0x040000BA RID: 186
	//[MarshalAs(UnmanagedType.I4)]
	int max_chan;

	// Token: 0x040000BB RID: 187
	//[MarshalAs(UnmanagedType.U8)]
	unsigned long maintenance_expiration_date;

	// Token: 0x040000BC RID: 188
	//[MarshalAs(UnmanagedType.U8)]
	unsigned long support_expiration_date;

	// Token: 0x040000BD RID: 189
	//[MarshalAs(UnmanagedType.I4)]
	__int32 max_wm_connections;

	// Token: 0x040000BE RID: 190
	//[MarshalAs(UnmanagedType.U8)]
	unsigned long last_erp_check_date;
};
