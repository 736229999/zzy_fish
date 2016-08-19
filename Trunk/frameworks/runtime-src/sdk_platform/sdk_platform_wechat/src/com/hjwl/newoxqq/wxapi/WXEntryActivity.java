package com.hjwl.newoxqq.wxapi;


import org.json.JSONException;
import org.json.JSONObject;

import com.hjwl.newoxqq.R;
import com.jt.sdk_platform_base.SDKControlOriginal;
import com.jt.sdk_platform_wechat.Constants;
import com.jt.sdk_platform_wechat.SDKControl;
import com.jt.user.UserLoginInfo;
import com.qp.lib.asynctask.ReadGetUrlAsyncTask;
import com.tencent.mm.sdk.constants.ConstantsAPI;
import com.tencent.mm.sdk.modelbase.BaseReq;
import com.tencent.mm.sdk.modelbase.BaseResp;
import com.tencent.mm.sdk.modelmsg.SendAuth;
import com.tencent.mm.sdk.modelmsg.ShowMessageFromWX;
import com.tencent.mm.sdk.modelmsg.WXAppExtendObject;
import com.tencent.mm.sdk.modelmsg.WXMediaMessage;
import com.tencent.mm.sdk.openapi.IWXAPI;
import com.tencent.mm.sdk.openapi.IWXAPIEventHandler;
import com.tencent.mm.sdk.openapi.WXAPIFactory;
import com.umeng.socialize.weixin.view.WXCallbackActivity;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class WXEntryActivity extends WXCallbackActivity implements IWXAPIEventHandler{
	
	private static final String TAG = "WXEntryActivity";
	
	// IWXAPI �ǵ�����app��΢��ͨ�ŵ�openapi�ӿ�
    private IWXAPI api;
	
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        
        // ͨ��WXAPIFactory��������ȡIWXAPI��ʵ��
    	api = WXAPIFactory.createWXAPI(this, Constants.APP_ID, false);
    	
        api.handleIntent(getIntent(), this);
    }

//	protected void onNewIntent(Intent intent) {
//		super.onNewIntent(intent);
//		
//		setIntent(intent);
//        api.handleIntent(intent, this);
//	}

	// ΢�ŷ������󵽵�����Ӧ��ʱ����ص����÷���
	@Override
	public void onReq(BaseReq req) {
		switch (req.getType()) {
		case ConstantsAPI.COMMAND_GETMESSAGE_FROM_WX:
//			goToGetMsg();		
			break;
		case ConstantsAPI.COMMAND_SHOWMESSAGE_FROM_WX:
//			goToShowMsg((ShowMessageFromWX.Req) req);
			break;
		default:
			break;
		}
	}

	// ������Ӧ�÷��͵�΢�ŵ�����������Ӧ�������ص����÷���
	@Override
	public void onResp(BaseResp resp) {
		super.onResp(resp);
		if(resp.getType() == 1){ //��¼
			int result = 0;
			switch (resp.errCode) {
			case BaseResp.ErrCode.ERR_OK:
	//			result = R.string.errcode_success;
				break;
			case BaseResp.ErrCode.ERR_USER_CANCEL:
				result = R.string.errcode_cancel;
				break;
			case BaseResp.ErrCode.ERR_AUTH_DENIED:
				result = R.string.errcode_deny;
				break;
			default:
				result = R.string.errcode_unknown;
				break;
			}
			
			if(result!=0){
				Toast.makeText(this,getString(result), Toast.LENGTH_SHORT).show();
				finish();
				return;
			}
			
			//��ȡcode
			String code = ((SendAuth.Resp) resp).code;
			Log.i(TAG, code);
			//��ȡtoken,�������û�����
			SDKControl.getAccessToken(code);
	//		finish();
		}
	}
}