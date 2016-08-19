package com.jt.sdk_platform_uc;

import org.json.JSONException;
import org.json.JSONObject;

import YYProjectJni.JniHelper;
import android.app.Activity;
import android.util.Log;
import android.widget.Toast;
import cn.uc.gamesdk.UCCallbackListener;
import cn.uc.gamesdk.UCCallbackListenerNullException;
import cn.uc.gamesdk.UCFloatButtonCreateException;
import cn.uc.gamesdk.UCGameSDK;
import cn.uc.gamesdk.UCGameSDKStatusCode;
import cn.uc.gamesdk.UCLogLevel;
import cn.uc.gamesdk.UCLoginFaceType;
import cn.uc.gamesdk.UCOrientation;
import cn.uc.gamesdk.info.FeatureSwitch;
import cn.uc.gamesdk.info.GameParamInfo;
import cn.uc.gamesdk.info.OrderInfo;
import cn.uc.gamesdk.info.PaymentInfo;

import com.jt.data.ProductInfoItem;
import com.jt.sdk_platform_base.SDKControlOriginal;
import com.jt.user.UserLoginInfo;
import com.qp.lib.asynctask.ReadGetUrlAsyncTask;
import com.qp.lib.asynctask.ReadPostUrlAsyncTask;
import com.qp.lib.asynctask.ReadGetUrlAsyncTask.ReadGetExecute;
import com.qp.lib.asynctask.ReadPostUrlAsyncTask.ReadPostExecute;

public class SDKControl extends SDKControlOriginal {
	public static final String TAG = "SDKControl";

	private final boolean IS_UC_SDK_DEBUG_MODE = false;
	private String UC_LOGIN_POST_URL = "http://sdk.g.uc.cn/cp/account.verifySession";
	private final String UC_API_KEY = "b4e96f1da2874e1cadf89de8b3eeee84";
	private final String UC_CP_ID = "50622";
	private final int UC_GAME_ID = 681562;
	private final String UC_SEVER_ID = "0";

	private Boolean isInit = false;
	
	public SDKControl(){
		
	}
	
	@Override
	public byte AccountType() {
		return (byte) _UCAccount;
	}

	@Override
	public void CCLoginType(JSONObject response) {
		JSONObject j1 = new JSONObject();
		try {
			j1.put("loginType", _UCAccount);
			j1.put("visible", true);
		} catch (JSONException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		SendMessageWithParameters("ccNd_PlatForm_LogonType", j1);
	}

	@Override
	public void CCGameLogin(JSONObject response) {
		// TODO Auto-generated method stub
		if(isInit){
			ucSdkLogin();
		}else{
			ucSdkInit();
		}
	}

	public void ucSdkInit() {

		if (IS_UC_SDK_DEBUG_MODE) {
			// ���Ի�����
			UC_LOGIN_POST_URL = "http://sdk.test4.g.uc.cn/cp/account.verifySession";
		} else {
			// ��ʽ������
			UC_LOGIN_POST_URL = "http://sdk.g.uc.cn/cp/account.verifySession";
		}
		
		UCCallbackListener<String> logoutListener = new UCCallbackListener<String>() {
			@Override
			public void callback(int statuscode, String data) {
				switch (statuscode) {
				case UCGameSDKStatusCode.NO_INIT:
					break;
				case UCGameSDKStatusCode.NO_LOGIN:
					break;
				case UCGameSDKStatusCode.SUCCESS:
					break;
				case UCGameSDKStatusCode.FAIL:
					break;
				default:
					break;
				}

			}
		};

		GameParamInfo gpi = new GameParamInfo();
		// gpi.setCpId(0); // �˲����ѷ���,Ĭ�ϴ���0����
		gpi.setGameId(UC_GAME_ID); // ��UC���ο���ƽ̨��ȡ�Լ���Ϸ�Ĳ�����Ϣ
		 gpi.setServerId(0); // �˲����ѷ���,Ĭ�ϴ���0����
		// gpi.setChannelId(2); // ������ͳһ�����Ѳ������ã��˲����ѷ���
		// �����Ƿ�֧�ֲ�ѯ��ֵ��ʷ����ʾ�л��˺Ź��ܣ���������ã�Ĭ�Ͼ��в�ѯ��ֵ��ʷ��¼���������л��˻�����
		gpi.setFeatureSwitch(new FeatureSwitch(true, false));
		try {
			// ����SDK��¼����Ϊ�������������UCOrientation.LANDSCAPE��ʱΪ������
			UCGameSDK.defaultSDK().setOrientation(UCOrientation.LANDSCAPE);
			// ������Ҫ֧���˻��л�/�˳��˺ŵ���Ϸ�������ڴ������˳�������
			UCGameSDK.defaultSDK().setLogoutNotifyListener(logoutListener);
			// ���õ�¼���棺
			// USE_WIDGET - ����¼����
			// USE_STANDARD - ��׼���¼����
			UCGameSDK.defaultSDK().setLoginUISwitch(UCLoginFaceType.USE_WIDGET);
			UCGameSDK.defaultSDK().initSDK((Activity) _context,
					UCLogLevel.WARN, IS_UC_SDK_DEBUG_MODE, gpi,
					new UCCallbackListener<String>() {
						@Override
						public void callback(int code, String msg) {
							isInit = true;
							switch (code) {
							case UCGameSDKStatusCode.SUCCESS:
								// ��ʼ���ɹ�,����ִ�к����ĵ�¼��ֵ����
								ucSdkLogin();
								break;
							case UCGameSDKStatusCode.INIT_FAIL:
								// ��ʼ��ʧ��,���ܽ��к�������
								break;
							default:
								break;
							}
						}
					});
		} catch (UCCallbackListenerNullException e) {
			// TODO ����listenerΪnull���쳣
		}
	}

	public void ucSdkLogin() {
		try {
			UCGameSDK.defaultSDK().login((Activity) _context,
					new UCCallbackListener<String>() {
						@Override
						public void callback(int code, String msg) {
							if (code == UCGameSDKStatusCode.SUCCESS) {
								// ��¼�ɹ�������ִ�к�������
								String sid = UCGameSDK.defaultSDK().getSid();
								getUserInfoFromUc(sid);
							}
							if (code == UCGameSDKStatusCode.LOGIN_EXIT) {
								// ��¼����رգ���Ϸ���жϴ�ʱ�Ƿ��ѵ�¼�ɹ�������Ӧ����
							}
							if (code == UCGameSDKStatusCode.NO_INIT) {
								// û�г�ʼ���ͽ��е�¼���ã���Ҫ��Ϸ����SDK��ʼ������
							}
						}
					});
		} catch (UCCallbackListenerNullException e) {
			// �쳣����
			Log.e("ucSdkLogin exception ****", "e.message = " + e.getMessage());
		}

	}

	public void getUserInfoFromUc(String sid) {

		// "id":1330395827,
		// "data":{"sid":"abcdefg123456"},
		// "game":{"gameId":12345},
		// "sign":"6e9c3c1e7d99293dfc0c81442f9a9984"

		// MD5ǩ��
		String toMD5 = "sid=" + sid + UC_API_KEY;
		String sign = MD5.md5(toMD5);

		JSONObject jParam = new JSONObject();
		try {
			JSONObject jDataParam = new JSONObject();
			jDataParam.put("sid", sid);
			JSONObject jGameParam = new JSONObject();
			jGameParam.put("gameId", UC_GAME_ID);

			jParam.put("id", System.currentTimeMillis());
			jParam.put("data", jDataParam);
			jParam.put("game", jGameParam);
			jParam.put("sign", sign);
		} catch (JSONException e2) {
			// TODO Auto-generated catch block
			e2.printStackTrace();
		}

		// ��ȡ�û�����
		ReadPostUrlAsyncTask post = new ReadPostUrlAsyncTask(UC_LOGIN_POST_URL,
				"", jParam);
		post.addReadPostExecute(new ReadPostExecute() {

			@Override
			public void onPostExecute(String str) {
				try {
					JSONObject response = new JSONObject(str);

					JSONObject stateJobj = response.getJSONObject("state");
					int code = stateJobj.getInt("code");
					String msg = stateJobj.getString("msg");

					if (code == 1) {
						// ��ȡ�ɹ�
						UserLoginInfo userLogoInfo = getUserLogoInfo();
						userLogoInfo.reset();

						JSONObject dataJobj = response.getJSONObject("data");
						String accountId = dataJobj.getString("accountId");
						uuid = accountId;
						String nickName = dataJobj.getString("nickName");

						userLogoInfo.setAcccount(nickName);
						userLogoInfo.setAccountType(_UCAccount);
						userLogoInfo.setFaceID(uuid);

						userLogoInfo.setBigFace("");
						userLogoInfo.setGender(0);
						onLoginResulet(1);
					} else {
						Toast.makeText(_context,
								"code:" + code + ",msg:" + msg,
								Toast.LENGTH_LONG).show();
						onLoginResulet(0);
					}
				} catch (JSONException e) {
					e.printStackTrace();
				}
			}
		});
		post.execute("");
	}

	public void onLoginResulet(int result) {
		if (uuid.length() <= 2) {
			result = 0;
		}

		if (uuid.length() != 0) {
			try {
				// ����������ť
				UCGameSDK.defaultSDK().createFloatButton((Activity) _context,
						new UCCallbackListener<String>() {
							@Override
							public void callback(int statuscode, String data) {
								if (statuscode == UCGameSDKStatusCode.SDK_OPEN) {
									// ��Ҫ��SDK����
								} else if (statuscode == UCGameSDKStatusCode.SDK_CLOSE) {
									// ��Ҫ�ر�SDK���棬������Ϸ����

								}
							}
						});
				// ��ʾ����ͼ��
				UCGameSDK.defaultSDK().showFloatButton((Activity) _context,
						100, 50, true);
			} catch (UCCallbackListenerNullException e) {
				// SDK������Ϣ������Ϊ��
			} catch (UCFloatButtonCreateException e) {
				// ����������ť�쳣
			}
		}

		JSONObject jUser = new JSONObject();
		UserLoginInfo userLogoInfo = getUserLogoInfo();
		try {
			jUser.put("result", result);
			jUser.put("acccount", userLogoInfo.getAcccount());
			jUser.put("uuid", uuid);
			jUser.put("accountType", userLogoInfo.getAccountType());
			jUser.put("szMachineID", JniHelper.m_Mac);
			jUser.put("bigFace", userLogoInfo.getBigFace());
			jUser.put("gender", userLogoInfo.getGender());
		} catch (JSONException e) {
			e.printStackTrace();
		}
		Log.i(TAG, userLogoInfo.toString());
		Log.i(TAG, "onLoginResulet:" + result);
		SendMessageWithParameters("ccNd_Platform_LogonResult", jUser);
	}

	@Override
	public void CCGameLogout(JSONObject response) {
		super.CCGameLogout(response);
	}

	@Override
	public void onDestroy() {
		super.onDestroy();
	}

	@Override
	public void CCPay(JSONObject response) {
		String type = null;
		String gameID = null;
		String userID = null;
		String ProductName = null;
		String Description = null;
		String Price = null;
		int appid = 0;
		String ProductID = null;
		String NotifyURL = null;
		String domainURL = null;
		try {
			type = response.getString("type");
			gameID = response.getString("gameID");
			userID = response.getString("userID");
			ProductName = response.getString("ProductName");
			Description = response.getString("Description");
			Price = response.getString("Price");
			appid = response.getInt("appid");
			ProductID = response.getString("ProductID");
			NotifyURL = response.getString("NotifyURL");
			domainURL = response.getString("domainURL");
		} catch (JSONException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		final String ip = domainURL;

		String url = ip + "/getorderno.aspx?" + "gameid=" + gameID
				+ "&productid=" + ProductID;
		
		final String notifyUrl = ip + "/ucnoticeurl.aspx";//֧���ɹ��ص���ַ
		final float amount = Integer.parseInt(Price);//�趨֧����0Ϊ�����ֵ���
		
		ReadGetUrlAsyncTask task = new ReadGetUrlAsyncTask(url, null, null);
		task.addReadGetExecute(new ReadGetExecute() {

			@Override
			public void onGetExecute(String str) {

				JSONObject response;
				try {
					response = new JSONObject(str);
					String orderId = response.getString("result");
					try {

						// ����Payment�������ڴ��ݳ�ֵ��Ϣ
						PaymentInfo pInfo = new PaymentInfo();
						pInfo.setServerId(0); // �˲����ѷ���,Ĭ�ϴ���0���� 
						// pInfo.setAllowContinuousPay(true); //�˲����ѷ���,Ĭ��Ϊfalse��
						// pInfo.setCustomInfo("custOrderId=PX299392#ip=139.91.192.29#...");
						// //���ó�ֵ�Զ���������˲��������κδ����ڳ�ֵ��ɺ�֪ͨ��Ϸ��������ֵ���ʱԭ�ⲻ��������Ϸ���������˲���Ϊ��ѡ������Ĭ��Ϊ�ա�������Ҫʹ�ô˲�������Ϸ����ֵǰ�������ж��´˲������ݵ�ֵ�Ƿ�������Ϊ���ٵ���ֵ�ӿڣ�ע�ⳤ�Ȳ��ܳ���250
		
						pInfo.setAmount(amount); // ��λ��Ԫ
						// ���������ֵ�Ľ���Ϊ��ѡ������Ĭ��Ϊ0��
						// ��������˴˽�Ϊ0�����ʾֻ�����û���ָ������ֵ�������ָ������ָ��Ϊ0�����ʾ�û��ڳ�ֵʱ��������ѡ�������ϣ������Ľ����ö����ֵ����Ϸ������յ��ص���Ϣ����У��amount
						// ֵ��ͻ����µ�ʱ���ݵ��Ƿ�һ��
						
						if(JniHelper.getAppDebug() != 0){
							pInfo.setAmount(0.01f);
						}
						
						pInfo.setNotifyUrl(notifyUrl);// �ص���ַ���Ǳ���������˴����û򿪷�ƽ̨¼�룬����ȡ�ͻ������õĵ�ַ�����ú���Ϸ��֧����ɺ�SDK�ص���ֵ��Ϣ���˵�ַ������Ϊ����httpͷ��URL��ʽ��
						pInfo.setTransactionNumCP(orderId);// ����CP���еĶ����ţ���Ϊ��ѡ������������Ҫʹ�ô˲�������Ϸ����ֵǰ�������ж��´˲������ݵ�ֵ�Ƿ�������Ϊ���ٵ���ֵ�ӿڣ�ע�ⳤ�Ȳ��ܳ���30
						
						UCGameSDK.defaultSDK().pay((Activity) _context, pInfo,
								payResultListener);
					} catch (UCCallbackListenerNullException e) {
						// �쳣����
					}

				} catch (JSONException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}

		});
		task.execute("");
	}

	private UCCallbackListener<OrderInfo> payResultListener = new UCCallbackListener<OrderInfo>() {
		@Override
		public void callback(int statudcode, OrderInfo orderInfo) {
			if (statudcode == UCGameSDKStatusCode.NO_INIT) {
				// û�г�ʼ���ͽ��е�¼���ã���Ҫ��Ϸ����SDK��ʼ������
			}
			if (statudcode == UCGameSDKStatusCode.SUCCESS) {

				onPayResult(1);
				// �ɹ���ֵ
				if (orderInfo != null) {
					String ordereId = orderInfo.getOrderId();// ��ȡ������
					float orderAmount = orderInfo.getOrderAmount();// ��ȡ�������
					int payWay = orderInfo.getPayWay();
					String payWayName = orderInfo.getPayWayName();
					Log.i(TAG, ordereId + "," + orderAmount + "," + payWay + "," + payWayName);
				}
			}
			if (statudcode == UCGameSDKStatusCode.PAY_USER_EXIT) {
				// �û��˳���ֵ���档
			}
			
			if (statudcode == UCGameSDKStatusCode.FAIL) {
				// ��ֵʧ��
				onPayResult(0);
			}
		}

	};
	
	public void onPayResult(int result) {
		SDKControlOriginal.getDelegate().onPayResult(1, result);
	}
	
	@Override
	public Boolean CCQueryExitGame(JSONObject response) {
		// TODO Auto-generated method stub
		super.CCQueryExitGame(response);
		
		if(!isInit){
			return false;
		}
		
		try {
			UCGameSDK.defaultSDK().logout();
		} catch (UCCallbackListenerNullException e) {
			// δ�����˳�������
		}
		UCGameSDK.defaultSDK().exitSDK((Activity) _context,
				new UCCallbackListener<String>() {
					@Override
					public void callback(final int statuscode, final String data) {
						if (UCGameSDKStatusCode.SDK_EXIT_CONTINUE == statuscode) {
							// �˼��������Ϸ�Ĵ���
//							Toast.makeText((Activity) _context, data,
//									Toast.LENGTH_LONG).show();
						} else if (UCGameSDKStatusCode.SDK_EXIT == statuscode) {
							// �ڴ˼����˳���Ϸ�Ĵ���
//							Toast.makeText((Activity) _context, data,
//									Toast.LENGTH_LONG).show();
							((Activity)_context).finish();
							System.exit(0);
						}
					}
				});
		UCGameSDK.defaultSDK().destoryFloatButton((Activity) _context);
		
		return true;
	}
	
}
