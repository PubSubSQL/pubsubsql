javac -d . api/NetHeader.java api/Client.java api/client.java api/Factory.java
jar cfv pubsubsql.jar pubsubsql/NetHeader.class pubsubsql/Client.class pubsubsql/client.class pubsubsql/Factory.class
javac -d . -cp pubsubsql.jar test/PubSubSQLTest.java