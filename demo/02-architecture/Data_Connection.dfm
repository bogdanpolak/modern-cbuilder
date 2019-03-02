object DataModule2: TDataModule2
  OldCreateOrder = False
  Height = 215
  Width = 309
  object FDConnection1: TFDConnection
    Params.Strings = (
      'ConnectionDef=SQLite_Demo')
    Connected = True
    LoginPrompt = False
    Left = 72
    Top = 32
  end
  object dsProductsBrws: TFDQuery
    Connection = FDConnection1
    SQL.Strings = (
      'SELECT ProductID, ProductName, '
      '  Suppliers.SupplierID, Suppliers.CompanyName As SupplierName,'
      '  Categories.CategoryID, Categories.CategoryName,'
      '  QuantityPerUnit, UnitPrice, UnitsInStock, '
      '  UnitsOnOrder, ReorderLevel, Discontinued '
      'FROM Products'
      
        'INNER JOIN Suppliers ON Products.SupplierID = Suppliers.Supplier' +
        'ID'
      
        'INNER JOIN Categories ON Products.CategoryID = Categories.Catego' +
        'ryID')
    Left = 191
    Top = 33
  end
end
