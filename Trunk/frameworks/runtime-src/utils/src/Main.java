import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Iterator;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import net.sf.json.JSONArray;
import net.sf.json.JSONObject;

public class Main {
	private static String versionCode = "";
	private static String versionName = "";
	private static int platform = Integer.MAX_VALUE;//����
	private static String compiledMode;//����ģʽ

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		if(args.length==2){
			platform = Integer.parseInt(args[1]);
		}else if(args.length==0){
			System.out.println("��������,args.length��"+args.length);
			return;
		}
		compiledMode = args[0];

		readConfig();

	}

	public static void readConfig() {
		// ��ȡ�����ļ�
		String root = "";
		StringBuilder content = new StringBuilder();
		try {
			File directory = new File( "");// ����Ϊ��
			root = directory.getCanonicalPath();
			
			if(!new File(root + "/sdk_platform_config.json").exists()){
				//java��������ģʽ��
				//��ȡ�ϼ�Ŀ¼����
				root = root.substring(0, root.lastIndexOf("\\"));
			}
			String courseFile = root + "/sdk_platform_config.json";

			FileInputStream fis = new FileInputStream(courseFile);
			InputStreamReader isr = new InputStreamReader(fis, "UTF-8");
			BufferedReader br = new BufferedReader(isr);
			while (br.ready() != false) {
				content.append(br.readLine());
				content.append("\r\n");
			}
			System.out.println("��ȡ���óɹ���"+courseFile);
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		if(content.length()==0){
			return;
		}
		
		// �޸�����
		JSONObject jsdk = null;
		JSONObject jobj = null;
		JSONObject sdk = null;
		String apkName = null;
		try {

			jobj = JSONObject.fromObject(content.toString());
			jsdk = jobj.getJSONObject("sdk_platform");
			versionCode = jobj.getString("versionCode");
			versionName = jobj.getString("versionName");
			System.out.println("Ŀ��汾��:"+versionCode);
			System.out.println("Ŀ��汾����:"+versionName);

		} catch (Exception e) {
			// TODO: handle exception
			e.printStackTrace();
			return;
		}
		
		int targetCount = 0;
		int totalCount = platform == Integer.MAX_VALUE ? jsdk.size() : 1;
		
		do{
			try{
				if(platform!=Integer.MAX_VALUE){
					//�������������
					sdk = jsdk.getJSONObject("sdk_platform_"+platform);
				}else{
					Iterator it = jsdk.keys(); 
					int currentCount = 0;
		            while (it.hasNext()) {
		            	String key = (String) it.next();
		            	if(currentCount==targetCount){
		            		sdk = jsdk.getJSONObject(key);
		            		break;
		            	}
	            		currentCount++;
		            }
				}
				targetCount++;
	            if(sdk.isNullObject()){
	            	System.out.println("��ǰ����������Ч, platform��"+platform);
	            	continue;
	            }
	            
	            //�޸İ汾��,�汾����
	            String path = root + sdk.getString("path") + "\\AndroidManifest.xml";
	            changeVersion(path, versionCode, versionName,false);
		        
				// �޸���Ŀ����
				JSONArray jarrRef = JSONArray
						.fromObject(sdk.getString("reference"));
				changeReference(root + "/proj.android/project.properties", jarrRef);
				
				//�޸���Ŀǩ���ļ�
				String keystore = sdk.getString("keystore");
				changeKeystore(root + "/proj.android/ant.properties",keystore);
				
				//�޸ĵ�����APK��
				apkName = sdk.getString("apkname");
				changeApkName(root+"/proj.android/build.xml",apkName);
			} catch (Exception e) {
				// TODO: handle exception
				e.printStackTrace();
				break;
			}
			
			System.out.println("��ʼ������Ŀ�ļ�");
			String cmd = null;
			// �滻AndroidManifest.xml�ļ�
			String input = root + (sdk.getString("path")) + "\\AndroidManifest.xml";
			String out = (root + "\\proj.android");
			cmd = "cmd.exe /C copy " + input + " " + out;
			runCmd(cmd,null);
			
			//��������
			boolean isPush = sdk.getBoolean("isPush");
			changePush(out+"\\AndroidManifest.xml",isPush);
			
			if(compiledMode.equals("change")){
				System.out.println("�޸���Ŀ�������");
			}else if(compiledMode.equals("debug") || compiledMode.equals("release")){
				System.out.println("��ʼ������������δ��apk������" + apkName);
				//ʹ��ǰ����clean
				cmd = "cmd.exe /C " + "ant clean";
				runCmd(cmd,root+"\\proj.android");
				
				//�������а�
//				cmd = "cmd.exe /C " + "cocos compile -p android -m release";
				cmd = "cmd.exe /C " + "ant " + compiledMode;
				runCmd(cmd,root+"\\proj.android");
				
				if(compiledMode.equals("release")){
//					String FileStr = root+ "\\..\\..\\publish\\android\\" + apkName + "-release-signed.apk";
					String FileStr = root+ "\\proj.android\\bin\\" + apkName + "-release.apk";
					File apkFlie = new File(FileStr);
					if(apkFlie.exists()){
						//��������APK������
						cmd = "cmd.exe /C " + "rename " + FileStr + " "  + apkName + ".apk";
						runCmd(cmd,null);
						System.out.println("apk�ļ���������" + apkName + ".apk");
						System.out.println("�ƶ�apk��publishĿ¼");
						cmd = "cmd.exe /C move " + root + "\\proj.android\\bin\\" + apkName + ".apk" + " " + root+ "\\..\\..\\publish\\android\\";
						runCmd(cmd,null);
						System.out.println("���������� �����δ��APK������"+apkName);
					}else{
						System.out.println("�������ʧ�ܣ�δ����apk�ļ���"+apkName);
					}
				}else{
					
				}
			}
		}while(targetCount<totalCount);
		
	}
		
	public static void changeVersion(String path, String versionCode,
			String versionName,boolean isOpenPush) {
		// long startT = System.currentTimeMillis();
		// System.out.println("start time:" + startT);
		try {
			// ��ȡ�ļ�
			FileInputStream fis = new FileInputStream(path);
			InputStreamReader isr = new InputStreamReader(fis, "UTF-8");
			BufferedReader br = new BufferedReader(isr);
			StringBuilder content = new StringBuilder();

			while (br.ready() != false) {
				content.append(br.readLine());
				content.append("\r\n");
			}

			// �滻�汾��
			String regex = "android:versionCode=\"\\d+\"";
			Pattern pattern = Pattern.compile(regex);
			Matcher matcher = pattern.matcher(content);
			if (matcher.find()) {
				content = content.replace(matcher.start(), matcher.end(),
						"android:versionCode=\"" + versionCode + "\"");
			}

			// �滻�汾����
			regex = "android:versionName=\".*\"";
			pattern = Pattern.compile(regex);
			matcher = pattern.matcher(content);
			if (matcher.find()) {
				content = content.replace(matcher.start(), matcher.end(),
						"android:versionName=\"" + versionName + "\"");
			}

			br.close();
			isr.close();
			// д���ļ�
			FileOutputStream fs = new FileOutputStream(path);
			OutputStreamWriter osw = new OutputStreamWriter(fs, "UTF-8");
			osw.write(content.toString());
			osw.flush();
			osw.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();

		} catch (IOException e) {
			e.printStackTrace();

		}
	}
	
	public static void changePush(String path,boolean isOpenPush) {
		// long startT = System.currentTimeMillis();
		// System.out.println("start time:" + startT);
		try {
			// ��ȡ�ļ�
			FileInputStream fis = new FileInputStream(path);
			InputStreamReader isr = new InputStreamReader(fis, "UTF-8");
			BufferedReader br = new BufferedReader(isr);
			StringBuilder content = new StringBuilder();

			while (br.ready() != false) {
				content.append(br.readLine());
				content.append("\r\n");
			}
			
			if(isOpenPush){
				String regex = "<!--JPush-permission-start";
				Pattern pattern = Pattern.compile(regex);
				Matcher matcher = pattern.matcher(content);
				if (matcher.find()) {
					content = content.replace(matcher.start(), matcher.end(),"");
				}
				
				regex = "JPush-permission-end-->";
				pattern = Pattern.compile(regex);
				matcher = pattern.matcher(content);
				if (matcher.find()) {
					content = content.replace(matcher.start(), matcher.end(),"");
				}
			}

			br.close();
			isr.close();
			// д���ļ�
			FileOutputStream fs = new FileOutputStream(path);
			OutputStreamWriter osw = new OutputStreamWriter(fs, "UTF-8");
			osw.write(content.toString());
			osw.flush();
			osw.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();

		} catch (IOException e) {
			e.printStackTrace();

		}
	}
	
	// �޸�ǩ��
	public static void changeKeystore(String path,String store) {
		try {
			// ��ȡ�ļ�
			FileInputStream fis = new FileInputStream(path);
			InputStreamReader isr = new InputStreamReader(fis, "UTF-8");
			BufferedReader br = new BufferedReader(isr);
			StringBuilder content = new StringBuilder();

			while (br.ready() != false) {
				content.append(br.readLine());
				content.append("\r\n");
			}

			// �滻ǩ��
			String regex = "key.store=.*?\\r\\n";
			Pattern pattern = Pattern.compile(regex);
			Matcher matcher = pattern.matcher(content);
			if (matcher.find()) {
				content = content.replace(matcher.start(), matcher.end(),
						"key.store=" + store + "\r\n");
			}

			br.close();
			isr.close();
			// д���ļ�
			FileOutputStream fs = new FileOutputStream(path);
			OutputStreamWriter osw = new OutputStreamWriter(fs, "UTF-8");
			osw.write(content.toString());
			osw.flush();
			osw.close();
			System.out.println("�޸�ǩ���ɹ���key.store="+store);
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	// �޸�����
	public static void changeReference(String path, JSONArray jarr) {
		try {
			// ��ȡ�ļ�
			FileInputStream fis = new FileInputStream(path);
			InputStreamReader isr = new InputStreamReader(fis, "UTF-8");
			BufferedReader br = new BufferedReader(isr);
			StringBuilder content = new StringBuilder();

			while (br.ready() != false) {
				content.append(br.readLine());
				content.append("\r\n");
			}

			// �滻������
			String regex = "android.library.reference.";
			int index = content.indexOf(regex);
			if (index != -1) {
				content = content.delete(index, content.length());
			}

			for (int i = 0; i < jarr.size(); i++) {
				String ref = regex + "" + (i + 1) + "="
						+ jarr.get(i).toString();
				System.out.println("���ÿ⣺" + ref);
				content.append(ref);
				content.append("\r\n");
			}

			br.close();
			isr.close();
			// д���ļ�
			FileOutputStream fs = new FileOutputStream(path);
			OutputStreamWriter osw = new OutputStreamWriter(fs, "UTF-8");
			osw.write(content.toString());
			osw.flush();
			osw.close();
			System.out.println("�޸����ÿ�ɹ�");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();

		}
	}
	
	//�޸ĵ�������
	public static void changeApkName(String path,String name){
		try {
			// ��ȡ�ļ�
			FileInputStream fis = new FileInputStream(path);
			InputStreamReader isr = new InputStreamReader(fis, "UTF-8");
			BufferedReader br = new BufferedReader(isr);
			StringBuilder content = new StringBuilder();

			while (br.ready() != false) {
				content.append(br.readLine());
				content.append("\r\n");
			}

			// �滻ǩ��
			String regex = "<project name=\".*?\"";
			Pattern pattern = Pattern.compile(regex);
			Matcher matcher = pattern.matcher(content);
			if (matcher.find()) {
				content = content.replace(matcher.start(), matcher.end(),
						"<project name=\"" + name + "\"");
			}

			br.close();
			isr.close();
			// д���ļ�
			FileOutputStream fs = new FileOutputStream(path);
			OutputStreamWriter osw = new OutputStreamWriter(fs, "UTF-8");
			osw.write(content.toString());
			osw.flush();
			osw.close();
			System.out.println("�޸�APK�������֣�"+name);
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	/**
	 * ִ��ָ��
	 * 
	 * @param cmd
	 */
	public static void runCmd(String cmd,String path) {
		Runtime rt = Runtime.getRuntime();
		BufferedReader br = null;
		InputStreamReader isr = null;
		try {
			
			Process p = null;
			if(path!=null){
				p = rt.exec(cmd,null,new File(path));
			}else
			{
				p = rt.exec(cmd);
			}
			
			//��ȡ����̨���
			isr = new InputStreamReader(p.getInputStream());
			br = new BufferedReader(isr);
			String msg = null;
			while ((msg = br.readLine()) != null) {
				System.out.println(msg);
			}
			
			//��ȡ������Ϣ
			if(p.getErrorStream().available() != 0){
				isr = new InputStreamReader(p.getErrorStream());
				br = new BufferedReader(isr);
				msg = null;
				while ((msg = br.readLine()) != null) {
					System.out.println(msg);
				}
			}
			
		} catch (Exception e) {
			System.out.println(e.getMessage());
			e.printStackTrace();
		} finally {
			try {
				if (isr != null) {
					isr.close();
				}
				if (br != null) {
					br.close();
				}
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
}
