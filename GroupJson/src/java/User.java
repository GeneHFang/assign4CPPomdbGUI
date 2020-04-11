package ser321.serialize;

import java.io.Serializable;
import org.json.JSONObject;

/**
 * Copyright (c) 2020 Tim Lindquist,
 * Software Engineering,
 * Arizona State University at the Polytechnic campus
 * <p/>
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation version 2
 * of the License.
 * <p/>
 * This program is distributed in the hope that it will be useful,
 * but without any warranty or fitness for a particular purpose.
 * <p/>
 * Please review the GNU General Public License at:
 * http://www.gnu.org/licenses/gpl-2.0.html
 * see also: https://www.gnu.org/licenses/gpl-faq.html
 * so you are aware of the terms and your rights with regard to this software.
 * Or, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,USA
 * <p/>
 * Purpose:
 * An class defining json serializable user objects.
 * <p/>
 * Ser321 Principles of Distributed Software Systems
 * @see <a href="http://pooh.poly.asu.edu/Ser321">Ser321 Home Page</a>
 * @author Tim Lindquist (Tim.Lindquist@asu.edu) CIDSE - Software Engineering
 *                       Ira Fulton Schools of Engineering, ASU Polytechnic
 * @file    User.java
 * @date    January, 2020
 * @license See above
 */
class User extends Object implements Serializable {

   // Serial version UID is defined below. Its only needed if you want
   // to make changes to the class and still deserialize artifacts
   // generated from prior versions. Obtain this definition with:
   // serialver -classpath classes:lib/json.jar ser321.serialize.User
   private static final long serialVersionUID = 3415902006212375222L;

   private String userId, userPwd;

   public User(String id, String pwd) {

      userId = id;
      userPwd = pwd;
   }

   public User(JSONObject obj){
      userId = obj.getString("userId");
      userPwd = obj.getString("userPwd");
   }

   public JSONObject toJSONObject(){
      JSONObject obj = new JSONObject();
      obj.put("userId",userId);
      obj.put("userPwd",userPwd);
      //System.out.println("User toJSONObject returning: "+obj.toString());
      return obj;
   }

   protected String getId() {
      return userId;
   }

   protected boolean check(String id, String pwd) {
      return (userId.equals(id) && userPwd.equals(pwd));
   }

}
    
