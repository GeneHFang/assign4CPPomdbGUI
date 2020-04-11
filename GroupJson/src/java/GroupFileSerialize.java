package ser321.serialize;

import java.io.PrintWriter;
import java.io.File;
import java.io.ObjectOutputStream;
import java.io.ObjectInputStream;
import java.io.FileOutputStream;
import java.io.FileInputStream;

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
 * A class to demonstrate transferring a user-defined object via a file
 * using json serialization. Serialized object Group includes User objects.
 * <p/>
 * Ser321 Principles of Distributed Software Systems
 * @see <a href="http://pooh.poly.asu.edu/Ser321">Ser321 Home Page</a>
 * @author Tim Lindquist (Tim.Lindquist@asu.edu) CIDSE - Software Engineering
 *                       Ira Fulton Schools of Engineering, ASU Polytechnic
 * @file    GroupFileSerialize.java
 * @date    January, 2020
 * @license See above
 * @see ser321.serialize.Group
 * @see ser321.serialize.User
 */
public class GroupFileSerialize {
  public static void main (String args[]) {

    try {
      Group admin = new Group();
      admin.setName("Administration");
      admin.addUserToGroup("Tim","timWord");
      admin.addUserToGroup("Joe","joeWord");
      admin.addUserToGroup("Sue","sueWord");
      admin.printGroup();

      System.out.println("Administration group as json string: "+
                         admin.toJSONString());

      PrintWriter out = new PrintWriter("admin.json");
      out.println(admin.toJSONString());
      out.close();
      System.out.println("Done exporting group in json to admin.json");

      // Input the group from admin.json
      System.out.println("Importing group from admin.json");
      Group adminToo = new Group("admin.json");
      adminToo.printGroup();

      // now use java's built in serialization to serialize and deserialize
      File outFile = new File("admin.ser");
      ObjectOutputStream os = 
                         new ObjectOutputStream(new FileOutputStream(outFile));
      os.writeObject(admin);
      os.flush();
      System.out.println("Used Java serialization of the group to admin.ser");
      os.close();

      File inFile = new File("admin.ser");
      ObjectInputStream in =
                            new ObjectInputStream(new FileInputStream(inFile));
      Group groupAgain = (Group)in.readObject();
      System.out.println("Done importing the group from admin.ser as:");
      groupAgain.printGroup();
      in.close();

    }catch(Exception e) {
       System.out.println("exception: "+e.getMessage());
       e.printStackTrace();
    }
  }
}
